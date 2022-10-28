#include <iostream>
#include <vector>
#include <assert.h>
#include <Windows.h>

using namespace std;



//Worker id, name, surname, age, pageCount ++
//WorkerQueue
//Printer workerQueue
//start - 
//Printer clasinin ichinde workerQueue saxlanilmalidir
//ve printer in start methodu chagrilan kimi
//novbede olan ishchilerin kagizlari ksersks olsun
//kserks emeliyyati bitenden sonra ishci siradan dequeue olunsun
//novbe boshalana qeder bu proses davam etmelidir



class Worker {
	int id;
	static int staticid;
	string name;
	string surname;
	int age;
	int pageCount;

public:

	Worker()
	{
		id = staticid++;
		name = "";
		surname = "";
		age = 0;
		pageCount = 0;
	}

	Worker(string name, string surname, int age, int pageCount)
	{
		id = staticid++;
		SetName(name);
		SetSurname(surname);
		SetAge(age);
		SetPageCount(pageCount);
	}

#pragma region Setters

	void SetId(int id) {
		this->id = id;
	}

	void SetName(string name) {
		this->name.assign(name);
	}

	void SetSurname(string surname) {
		this->surname.assign(surname);
	}

	void SetAge(int age) {
		this->age = age;
	}

	void SetPageCount(int pageCount) {
		this->pageCount = pageCount;
	}

#pragma endregion

#pragma region Getters
	int GetId()const { return id; }
	string GetName()const { return name; }
	string GetSurname()const { return surname; }
	int GetAge()const { return age; }
	int GetPageCount()const { return pageCount; }
#pragma endregion

	void Show() {
		cout << "Id: " << id << "\nName: " << name << "\nSurname: " << surname << "\nAge: " << age << "\nPage Count: " << pageCount << endl << endl;
	}

	friend class WorkerQueue;
	friend class Printer;
};
int Worker::staticid = 1;





class WorkerQueue {
	vector<Worker> workers;

public:

	bool IsEmpty()const { return workers.empty(); }

	void Enqueue(const Worker& worker) {
		workers.push_back(worker);
	}

	void Dequeue() {
		assert(!IsEmpty() && "Queue is empty");
		workers.erase(workers.begin());
	}

	Worker& Front() {
		return workers.front();
	}

	friend class Printer;
};






class Printer {
	WorkerQueue workerQueue;
	
public:

	void AddWorker(const Worker& worker) {
		workerQueue.Enqueue(worker);
	}

	void Start() {
		while (!workerQueue.IsEmpty())
		{
			Worker worker = workerQueue.Front();
			while (0 < worker.pageCount) {
				system("cls");
				worker.Show();
				Sleep(1000);
				worker.pageCount--;
			}

			workerQueue.Dequeue();
		}

	}
};




void main() {
	Worker w("Toghrul", "Azizli", 18, 4);
	Worker w1("Hakuna", "Matata", 42, 3);
	
	Printer pr;
	pr.AddWorker(w);
	pr.AddWorker(w1);
	pr.Start();
}