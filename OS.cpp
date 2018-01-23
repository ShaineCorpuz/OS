#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void gotoxy(short x, short y) {
		COORD pos = {x, y};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		
void t(short c){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

	typedef struct{
		int Number;
		int Priority;
		float Arrival_Time;
		float Burst_Time;
		float Waiting_Time;
		float Turnaround_Time;
		float Deadline;
	}CPU_Process;
	
void FCFS(CPU_Process*,int);
void SJF(CPU_Process*, int);
void Priority_Alg(CPU_Process*, int);
void Deadline(CPU_Process*, int);
void Preemptive_Priority(CPU_Process*, int);
void calculate(CPU_Process*, int, float&, float&, float&);
void GanttChart(CPU_Process*,int);

	
int main(){
	
	int number = 0,ctr=0,choice,pick;
	char ans;
	CPU_Process *Process;
here:		
	t(13); gotoxy(27,1); cout << "CPU SCHEDULING ALGORITHMS" << endl;
	t(13); gotoxy(18,3); cout << "[1]"; t(15); cout << " Non Preemptive" << endl;
	t(13); gotoxy(18,4); cout << "[2]"; t(15); cout << " Preemptive" << endl;
	t(13); gotoxy(18,5); cout << "[3]"; t(15); cout << " EXIT" << endl;
	t(11); gotoxy(18,8); cout << "Choice: ";
			cin >> pick;
	if(pick==1){
	
	while(1){
		system("cls");
		do{
		t(11); gotoxy(25,0); cout << char(201); gotoxy(25,1); cout << char(186);
			   gotoxy(25,2); cout << char(200); gotoxy(53,0); cout << char(187);
			   gotoxy(53,2); cout << char(188); gotoxy(53,1); cout << char(186);
		t(13); gotoxy(27,1); cout << "CPU SCHEDULING ALGORITHMS" << endl;
		t(13); gotoxy(18,3); cout << "[1]"; t(15); cout << " First Come First Serve (FCFS) Algorithm" << endl;
		t(13); gotoxy(18,4); cout << "[2]"; t(15); cout << " Shortest Job First (SJF) Algorithm" << endl;
		t(13); gotoxy(18,5); cout << "[3]"; t(15); cout << " Priority Algorithm" << endl;
		t(13); gotoxy(18,6); cout << "[4]"; t(15); cout << " Deadline Algorithm" << endl;
		t(13); gotoxy(18,7); cout << "[5]"; t(15); cout << " Back to Main" << endl;
		t(11); gotoxy(18,9); cout << "Choice: ";
					cin >> choice; 
				system("cls");
	}while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
	
	switch(choice){
		case 1 : t(13);	gotoxy(20,1); cout << "First Come First Serve (FCFS) Algorithm" << endl << endl;
				 t(15);	cout << "Enter the number of process(s): ";
						cin >> number; cout << endl;
							Process = new CPU_Process[number];
							FCFS(Process,number);
							delete Process;
					break;
		case 2 : t(13);	gotoxy(23,1); cout << "Shortest Job First (SJF) Algorithm" << endl << endl;
				 t(15);	cout << "Enter the number of process(s): ";
						cin >> number; cout << endl;
							Process = new CPU_Process[number];
							SJF(Process,number);
							delete Process;
				 	break;
		case 3 : t(13);	gotoxy(31,1);cout << "Priority Algorithm" << endl << endl;
				 t(15);	cout << "Enter the number of process(s): ";
						cin >> number; cout << endl;
							Process = new CPU_Process[number];
							Priority_Alg(Process,number);
							delete Process;
				 	break;
		case 4 : t(13);	gotoxy(31,1);cout << "Deadline Algorithm" << endl << endl;
				 t(15);	cout << "Enter the number of process(s): ";
				 		cin >> number; cout << endl;
							Process = new CPU_Process[number];
							Deadline(Process,number);
							delete Process;
				 	break;
		case 5 : goto here; break;
		}		
		cout << endl;
		cout << "Would you like to try again? [y/n]";
		cin >> ans;
			if(toupper(ans) == 'Y'){
				continue;
			}
			else{
				break;
			}		
	}
	}
	
	else if(pick==2){
		
		while(1){
		system("cls");
		do{
		t(11); gotoxy(25,0); cout << char(201); gotoxy(25,1); cout << char(186);
			   gotoxy(25,2); cout << char(200); gotoxy(53,0); cout << char(187);
			   gotoxy(53,2); cout << char(188); gotoxy(53,1); cout << char(186);
		t(13); gotoxy(27,1); cout << "CPU SCHEDULING ALGORITHMS" << endl;
		t(13); gotoxy(18,3); cout << "[1]"; t(15); cout << " Preemptive Priority Algorithm" << endl;
		t(13); gotoxy(18,4); cout << "[2]"; t(15); cout << " Preemptive Shortest Job First Algorithm" << endl;
		t(13); gotoxy(18,5); cout << "[3]"; t(15); cout << " Round Robin Algorithm" << endl;
		t(13); gotoxy(18,6); cout << "[4]"; t(15); cout << " Round Robin Over Head Algorithm" << endl;
		t(13); gotoxy(18,7); cout << "[5]"; t(15); cout << " Back to Main" << endl;
		t(11); gotoxy(18,9); cout << "Choice: ";
					cin >> choice; 
				system("cls");
	}while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
	
	switch(choice){
		case 1 : t(13);	gotoxy(20,1); cout << "Preemptive Priority Algorithm" << endl << endl;
				 t(15);	cout << "Enter the number of process(s): ";
						cin >> number; cout << endl;
							Process = new CPU_Process[number];
							delete Process;
					break;
		case 2 : t(13);	gotoxy(23,1); cout << "Preemptive Shortest Job First Algorithm" << endl << endl;
				 t(15);	cout << "Enter the number of process(s): ";
						cin >> number; cout << endl;
							Process = new CPU_Process[number];
							delete Process;
				 	break;
		case 3 : t(13);	gotoxy(31,1);cout << "Round Robin Algorithm" << endl << endl;
				 t(15);	cout << "Enter the number of process(s): ";
						cin >> number; cout << endl;
							Process = new CPU_Process[number];\
							delete Process;
				 	break;
		case 4 : t(13);	gotoxy(31,1);cout << "Round Robin Over Head Algorithm" << endl << endl;
				 t(15);	cout << "Enter the number of process(s): ";
				 		cin >> number; cout << endl;
							Process = new CPU_Process[number];
							Deadline(Process,number);
				 	break;
		case 5 : goto here; break;
		}		
		cout << endl;
		cout << "Would you like to try again? [y/n]";
		cin >> ans;
			if(toupper(ans) == 'Y'){
				continue;
			}
			else{
				break;
			}		
	}	
	}
	else
	return 0;
}

void FCFS(CPU_Process *Process, int num){
	
	int ctr=0;
	float btSum = 0.00, AverageWT = 0.00, AverageTT = 0.00;
	
	t(13); gotoxy(3,5); cout << "Jobs\t" << "  Arrival Time\t" << "  Burst Time\t" 
				 		<< "Waiting Time\t" << "Turnaround Time" << endl;
	t(15);
	for(ctr = 0; ctr < num; ctr++){
		Process[ctr].Number = Process[ctr].Priority = ctr+1;
		gotoxy(5,6+ctr); cout << Process[ctr].Number;
	}
	for(ctr = 0; ctr < num; ctr++){
		gotoxy(15,6+ctr); cin >> Process[ctr].Arrival_Time;
	}
	for(ctr = 0; ctr < num; ctr++){
		gotoxy(30,6+ctr); cin >> Process[ctr].Burst_Time;
	}
	
	calculate(Process,num,AverageTT,AverageWT,btSum);

 	for(ctr=0;ctr<num;ctr++){
		gotoxy(45,6+ctr); cout << Process[ctr].Waiting_Time;
		gotoxy(62,6+ctr); cout << Process[ctr].Turnaround_Time << endl << endl;
	}
	t(13); cout << "Gantt Chart:" << endl; GanttChart(Process,num);
	cout << endl << endl;
	t(13); cout << "\tAverage Waiting Time: "; t(15); cout << AverageWT << endl;
	t(13); cout << "\tAverage Turnaround Time: "; t(15); cout << AverageTT << endl;
	cout << endl;
	
	system("pause");
}

void SJF(CPU_Process *Process, int num){
	CPU_Process temp;
	int zroctr=0;
	
	int ctr=0,i,j;
	float btSum = 0.00, AverageWT = 0.00, AverageTT = 0.00;
	
	t(13); gotoxy(3,5); cout << "Jobs\t" << "  Arrival Time\t" << "  Burst Time\t" 
				 		<< "Waiting Time\t" << "Turnaround Time" << endl;
	t(15);
	for(ctr = 0; ctr < num; ctr++){
		Process[ctr].Number = Process[ctr].Priority = ctr+1;
		gotoxy(5,6+ctr); cout << Process[ctr].Number;
	}
	for(ctr = 0; ctr < num; ctr++){
		gotoxy(15,6+ctr); cin >> Process[ctr].Arrival_Time;
	}
	for(ctr = 0; ctr < num; ctr++){
		gotoxy(30,6+ctr); cin >> Process[ctr].Burst_Time;
	}
	
		for(int i = 1; i < num; i++){
			for(int j = i+1; j<num; j++){
				if(Process[i].Burst_Time > Process[j].Burst_Time){
					temp = Process[i];
					Process[i] = Process[j];
					Process[j] = temp;
				}
			}
		}	
	
	system("cls");	
	t(13); gotoxy(23,1); cout << "Shortest Job First (SJF) Algorithm" << endl;
				  
		gotoxy(3,5); cout << "Jobs\t" << "  Arrival Time\t" << "  Burst Time\t" 
				 		<< "Waiting Time\t" << "Turnaround Time" << endl;
				 		
	calculate(Process,num,AverageTT,AverageWT,btSum);
 	t(15);
 	for(ctr=0;ctr<num;ctr++){
 		gotoxy(5,6+ctr); cout << Process[ctr].Number;
 		gotoxy(15,6+ctr); cout << Process[ctr].Arrival_Time;
 		gotoxy(30,6+ctr); cout << Process[ctr].Burst_Time;
		gotoxy(45,6+ctr); cout << Process[ctr].Waiting_Time;
		gotoxy(62,6+ctr); cout << Process[ctr].Turnaround_Time << endl << endl;
	}
	t(13); cout << "Gantt Chart:" << endl; GanttChart(Process,num);
	cout << endl << endl;
	t(13); cout << "\tAverage Waiting Time: "; t(15); cout << AverageWT << endl;
	t(13); cout << "\tAverage Turnaround Time: "; t(15); cout << AverageTT << endl;
	cout << endl;
	
	system("pause");

}

void Priority_Alg(CPU_Process* Process, int num){
	CPU_Process temp;
	int ctr=0,i,j;
	float btSum = 0.00, AverageWT = 0.00, AverageTT = 0.00;
	t(13);
	gotoxy(2,5);  cout << "Jobs\t";
	gotoxy(9,5);  cout << " Arrival Time\t";
	gotoxy(24,5); cout << " Burst Time\t"; 
	gotoxy(37,5); cout << "Priority\t";
	gotoxy(48,5); cout << "Waiting Time\t"; 
	gotoxy(63,5); cout << "Turnaround Time"; 
					  
	t(15);
	for(ctr = 0; ctr < num; ctr++){
		Process[ctr].Number = ctr+1;
		gotoxy(4,6+ctr); cout << Process[ctr].Number;
	}
	for(ctr = 0; ctr < num; ctr++){
		gotoxy(15,6+ctr); cin >> Process[ctr].Arrival_Time;
	}
	for(ctr = 0; ctr < num; ctr++){
		gotoxy(29,6+ctr); cin >> Process[ctr].Burst_Time;
	}
	for(ctr = 0; ctr < num; ctr++){
		gotoxy(41,6+ctr); cin >> Process[ctr].Priority;
	}

	
		for(int i = 1; i < num; i++){
			for(int j = i+1; j<num; j++){
				if(Process[i].Priority > Process[j].Priority){
					temp = Process[i];
					Process[i] = Process[j];
					Process[j] = temp;
				}
			}
		}	
	
	
	system("cls");	
	t(13);
	gotoxy(31,1); cout << "Priority Algorithm" << endl;
				  
	gotoxy(2,5);  cout << "Jobs\t";
	gotoxy(9,5);  cout << " Arrival Time\t";
	gotoxy(24,5); cout << " Burst Time\t"; 
	gotoxy(37,5); cout << " Priority\t";
	gotoxy(48,5); cout << "Waiting Time\t"; 
	gotoxy(63,5); cout << "Turnaround Time"; 
	
	calculate(Process,num,AverageTT,AverageWT,btSum);
	
 	t(15);
 	for(ctr=0;ctr<num;ctr++){
 		gotoxy(4,6+ctr);  cout << Process[ctr].Number;
 		gotoxy(15,6+ctr); cout << Process[ctr].Arrival_Time;
 		gotoxy(28,6+ctr); cout << Process[ctr].Burst_Time;
 		gotoxy(41,6+ctr); cout << Process[ctr].Priority;
		gotoxy(53,6+ctr); cout << Process[ctr].Waiting_Time;
		gotoxy(69,6+ctr); cout << Process[ctr].Turnaround_Time << endl << endl;
	}
	
	t(13); cout << "Gantt Chart:" << endl; GanttChart(Process,num);
	cout << endl << endl;
	t(13); cout << "\tAverage Waiting Time: "; t(15); cout << AverageWT << endl;
	t(13); cout << "\tAverage Turnaround Time: "; t(15); cout << AverageTT << endl;
	cout << endl;
	
	system("pause");
}

void Deadline(CPU_Process *Process, int num){
	CPU_Process temp;
	
	int ctr=0,i,j;
	float btSum = 0.00, AverageWT = 0.00, AverageTT = 0.00;
	t(13);
	gotoxy(2,5);  cout << "Jobs\t";
	gotoxy(9,5);  cout << " Arrival Time\t";
	gotoxy(24,5); cout << " Burst Time\t"; 
	gotoxy(37,5); cout << " Deadline\t";
	gotoxy(48,5); cout << "Waiting Time\t"; 
	gotoxy(63,5); cout << "Turnaround Time"; 
					  
	t(15);
	for(ctr = 0; ctr < num; ctr++){
		Process[ctr].Number = ctr+1;
		gotoxy(4,6+ctr); cout << Process[ctr].Number;
	}
	for(ctr = 0; ctr < num; ctr++){
		gotoxy(15,6+ctr); cin >> Process[ctr].Arrival_Time;
	}
	for(ctr = 0; ctr < num; ctr++){
		gotoxy(29,6+ctr); cin >> Process[ctr].Burst_Time;
	}
	for(ctr = 0; ctr < num; ctr++){
		gotoxy(41,6+ctr); cin >> Process[ctr].Deadline;
			if(Process[ctr].Deadline == 0 )
				Process[ctr].Deadline = 1000;	
	}
	
	
	
	for(int i = 0; i < num; i++){
		for(int j = i+1; j < num; j++){
				if(Process[i].Deadline > Process[j].Deadline){
					temp = Process[i];
					Process[i] = Process[j];
					Process[j] = temp;
				}
		}
	}
	
	for(int i = 0; i < num; i++){
		if(Process[i].Deadline == 1000)
			Process[i].Deadline = 0;
	}
	
	system("cls");	
	t(13);
	gotoxy(31,1); cout << "Deadline Algorithm" << endl;
				  
	gotoxy(2,5);  cout << "Jobs\t";
	gotoxy(9,5);  cout << " Arrival Time\t";
	gotoxy(24,5); cout << " Burst Time\t"; 
	gotoxy(37,5); cout << " Deadline\t";
	gotoxy(48,5); cout << "Waiting Time\t"; 
	gotoxy(63,5); cout << "Turnaround Time"; 
	
	calculate(Process,num,AverageTT,AverageWT,btSum);
 	t(15);
 	for(ctr=0;ctr<num;ctr++){
 		gotoxy(4,6+ctr);  cout << Process[ctr].Number;
 		gotoxy(15,6+ctr); cout << Process[ctr].Arrival_Time;
 		gotoxy(28,6+ctr); cout << Process[ctr].Burst_Time;
 		gotoxy(41,6+ctr); cout << Process[ctr].Deadline;
		gotoxy(53,6+ctr); cout << Process[ctr].Waiting_Time;
		gotoxy(69,6+ctr); cout << Process[ctr].Turnaround_Time << endl << endl;
		
	}
	t(13); cout << "Gantt Chart:" << endl; GanttChart(Process,num);
	cout << endl << endl;
	
	t(13); cout << "\tAverage Waiting Time: "; t(15); cout << AverageWT << endl;
	t(13); cout << "\tAverage Turnaround Time: "; t(15); cout << AverageTT << endl;
	cout << endl;
	
	system("pause");
	
}


void calculate(CPU_Process* P, int n, float &avett, float &avewt, float &sumbt){
	int ctr = 0;
	
		P[0].Waiting_Time = 0;
		avett = P[0].Turnaround_Time = P[0].Burst_Time;
		sumbt = P[0].Burst_Time;
	for(ctr = 1; ctr < n; ctr++){
			P[ctr].Waiting_Time = sumbt - P[ctr].Arrival_Time;
			sumbt += P[ctr].Burst_Time;
			avewt += P[ctr].Waiting_Time;
			P[ctr].Turnaround_Time = P[ctr].Waiting_Time + P[ctr].Burst_Time;
			avett += P[ctr].Turnaround_Time;
	}

	avewt /= n; // Average Waiting Time
 	avett /= n; // Average Turnaround Time
}

void GanttChart(CPU_Process* P, int n){
	int i = 0,j = 0, sum = 0;
	int Color[] = {9,10,11,12,13,14,15,1,2,3,4,5,6,7,8,16,17,18,19,20};
	
	cout << " ";
	for(i = 0; i < n; i++){
	t(Color[i]);
	cout << "J" << P[i].Number;
		for(j = 0; j <= P[i].Burst_Time-3; j++){
			cout << " ";
		}
	}
	cout << endl;
	cout << " ";
	for(i = 0; i < n; i++){
	t(Color[i]);
		for(j = 0; j < P[i].Burst_Time; j++){
			cout << char(219);
		}
	}
	cout << endl;
	cout << " ";
	for(i = 0; i < n; i++){
	t(Color[i]);
	cout << sum;
		if(sum >= 10){
			for(j = 1; j < P[i].Burst_Time-1; j++){
				cout << " ";
			}
		}else{
			for(j = 1; j <= P[i].Burst_Time-1; j++){
				cout << " ";
			}
		}
		sum+=P[i].Burst_Time;
	}
	cout << sum;
}







