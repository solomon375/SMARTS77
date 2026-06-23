/********************************************************************/
/* A Small Real Time System for the Real-Time laboratory            */
/* built by: A.Teitelbaum on an idea of H.G.Mendelbaum              */
/* Jerusalem College of Technology, 5759-64 (1999-03)               */
/* update  Tishrey   5777                                           */
/* APP77.CPP, an application to demonstrate SMARTS77  functioning   */
/********************************************************************/
#include "smarts77.h"

// mutex for protecting cout
Mutex outputMutex;

// user Functions
void a( )
{
	outputMutex.acquire();
	cout << "\n *************   A Start    *********************";
	outputMutex.release();
	for (int j=0; j <30; j++)
	{
		for (long i=0; i <200000; i++);
		outputMutex.acquire();
		cout << "A";
		outputMutex.release();
	}
	outputMutex.acquire();
	cout << "\n *************   A Finish   *********************";
	outputMutex.release();
}

void b( )
{
	outputMutex.acquire();
	cout << "\n *************   B Start    *********************";
	outputMutex.release();
	for (int j=0; j <23; j++)
	{
		for (long i=0; i < 200000; i++);
		outputMutex.acquire();
		cout << "B";
		outputMutex.release();
	}
	outputMutex.acquire();
	cout << "\n *************   B Finish   *********************";
	outputMutex.release();
}

void c( )
{
	outputMutex.acquire();
	cout << "\n *************   C Start    *********************";
	outputMutex.release();
	for (int j=0; j <23; j++)
	{
		for (long i=0; i < 200000; i++);
		outputMutex.acquire();
		cout << "C";
		outputMutex.release();
	}
	outputMutex.acquire();
	cout << "\n *************   C Finish   *********************";
	outputMutex.release();
}

void main( )
{
	clrscr();
	//switch to EDF insted of roundRobin ?
	// SMARTS.externalFunctions(timerInterruptHandler, scheduler, myTaskEnd, roundRobin);
	// SMARTS.externalFunctions(timerInterruptHandler, scheduler, myTaskEnd, EDF);
	SMARTS.externalFunctions(timerInterruptHandler, scheduler, myTaskEnd, RMS);
	SMARTS.declareTask(a,'A',50,3);
	SMARTS.declareTask(b,'B',70,4);
	SMARTS.declareTask(c,'C',100,5);
	SMARTS.runTheTasks();
}

