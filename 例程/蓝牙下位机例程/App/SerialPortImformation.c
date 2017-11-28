#include "SerialPortImformation.h"
#include <stdio.h>

void EventError()
{
	printf("\nif you see this, it means you DO NOT add your own function\n");
	printf("for more information,please look at http://zzshub.cn/\n");
}

void addSerialPortDate(unsigned char data,serialPortInfo *this)
{
	char i;
	for(i=0;i<BUFFERSIZE;i++)
	{
		this->serialPortQueueBuffer[i]=this->serialPortQueueBuffer[i+1];
	}
	this->serialPortQueueBuffer[BUFFERSIZE]=data;
}

void processButton(serialPortInfo *this)
{
	char i;
	for(i=0;i<BUFFERSIZE;i++)
	{
		if(this->serialPortQueueBuffer[i]=='F')
		{
			this->serialPortQueueBuffer[i]=0;
			if(this->serialPortQueueBuffer[i+1]=='1')
			{
				function1ButtonClickedEvent();
			}
			else if(this->serialPortQueueBuffer[i+1]=='2')
			{
				function2ButtonClickedEvent();
			}
			else if(this->serialPortQueueBuffer[i+1]=='3')
			{
				function3ButtonClickedEvent();
			}
			else if(this->serialPortQueueBuffer[i+1]=='4')
			{
				function4ButtonClickedEvent();
			}
			else if(this->serialPortQueueBuffer[i+1]=='S')
			{
				stopButtonClickedEvent();
			}
		}
	}	
}



void processData(serialPortInfo *this)
{
	char i=0;
	for(i=0;i<BUFFERSIZE-2;i++)
	{
		if(this->serialPortQueueBuffer[i]=='X')
		{
			this->serialPortQueueBuffer[i]=0;
			this->GoSpeedOld=this->GoSpeed;
			this->GoSpeed = (int)(10*(this->serialPortQueueBuffer[i+1]-'0') + (this->serialPortQueueBuffer[i+2]-'0'));
			
			if(this->serialPortQueueBuffer[i+2]>'9' || this->serialPortQueueBuffer[i+2]<'0')
				this->GoSpeed=0;
			
			if(this->serialPortQueueBuffer[i+1]=='-')
				this->GoSpeed = -(int)(10*(this->serialPortQueueBuffer[i+2]-'0') + (this->serialPortQueueBuffer[i+3]-'0'));
			
			if(this->GoSpeed>99)
				this->GoSpeed=0;
			if(this->GoSpeed<-99)
				this->GoSpeed=0;
			
			if(this->GoSpeed!=this->GoSpeedOld)
				speedchangeEvent(this->GoSpeed,this->TurnSpeed);
		}
		
		
		else if(this->serialPortQueueBuffer[i]=='Y')
		{
			this->serialPortQueueBuffer[i]=0;
			this->TurnSpeedOld=this->TurnSpeed;
			this->TurnSpeed = (int)(10*(this->serialPortQueueBuffer[i+1]-'0') + (this->serialPortQueueBuffer[i+2]-'0'));
			
			if(this->serialPortQueueBuffer[i+2]>'9' || this->serialPortQueueBuffer[i+2]<'0')
				this->TurnSpeed=0;
			
			if(this->serialPortQueueBuffer[i+1]=='-')
				this->TurnSpeed = -(int)(10*(this->serialPortQueueBuffer[i+2]-'0') + (this->serialPortQueueBuffer[i+3]-'0'));
			
			if(this->TurnSpeed>99)
				this->TurnSpeed=0;
			if(this->TurnSpeed<-99)
				this->TurnSpeed=0;
			
			if(this->TurnSpeed!=this->TurnSpeedOld)
				speedchangeEvent(this->GoSpeed,this->TurnSpeed);
		}
		
	}
}

void serialPortexec(serialPortInfo *serialPortInfo)
{
	processButton(serialPortInfo);
	processData(serialPortInfo);
}

__weak void speedchangeEvent(int xSpeed,int ySpeed)
{
	printf("\nxSpeed=%d  ySpeed=%d\n",xSpeed,ySpeed);
	EventError();
}

__weak void function1ButtonClickedEvent()
{
	
	printf("\nfunction1ButtonClicked\n");
	EventError();
}

__weak void function2ButtonClickedEvent()
{
	
	printf("\nfunction2ButtonClicked\n");
	EventError();
}

__weak void function3ButtonClickedEvent()
{
	
	printf("\nfunction3ButtonClicked\n");
	EventError();
}

__weak void function4ButtonClickedEvent()
{
	printf("\nfunction4ButtonClicked\n");
	EventError();
	
}

__weak void stopButtonClickedEvent()
{
	
	printf("\nstopCarButtonClicked\n");
	EventError();
	
}
