#pragma config(Sensor, S1,     sound,          sensorSoundDB)
#pragma config(Motor,  motorA,          A,             tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int clapcount=0;

void waitforclap()
{
	while(SensorValue(sound)<50)
	{
		motor[A]=0;
		wait1Msec(10);
		clearTimer(timer1);
	}
}
void flipswitch()
{
	while(SensorValue(sound)>=50)
	{
		motor[A]=0;
		wait1Msec(10);
	}
		if(clapcount==2)
		{
			motor[A]=25;
			wait1Msec(1000);
		}
			if(clapcount==4)
			{
				motor[A]=-25;
				wait1Msec(1000);
			}

}
task main()
{
	while(true)
	{
	displayBigTextLine(4, "var: %d", clapcount);
		waitforclap();
		if(getTimerValue(timer1)>1000)
		{
		}
			else
			{
				clapcount=clapcount+1;
			}
				if(clapcount>4)
				{
					clapcount=1;
				}
					flipswitch();
	}




}
