const int MAXSIZE = 50;
const int NUMSIZE = 10;
bool flag = 0;
int workerCounter = 0; //количество уже добавленных сотрудников
struct Worker
{
	char* name = new char[MAXSIZE];
	char* surname = new char[MAXSIZE];
	char* phoneNumber = new char[NUMSIZE];
	double salary;
};
void showInfo(Worker worker);
void readFile(const char* path);
bool correctNumber(char* phoneNum);
void salaryDiapason(Worker worker, int left, int right);
void addWorker(char path[]);
void searchBySurname();
void sortBySurname();
Worker* deleteWorker();



Worker* workbook = new Worker[MAXSIZE]; //максимальное количество работников в книге пускай будет 50