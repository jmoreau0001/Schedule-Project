#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <iomanip>

///////////////////////////////////////////////////////////////////////////////////

class Schedule
{
	private:

		//Parts of the date
		int hour;
		std::string minute;
		//This will be what is scheduled for that day
		std::string plan;
		//This will be the number determining the day of the week
		int daynumber;
		//This will be the entered day as a number
		int day;
		//This will be the entered month as a number
		int month;
		//This will be the entered year as a number
		int year;

	public:

		//This initializes all values
		Schedule(int, std::string, std::string, int, int, int);
		//This will set the hour from the user
		void setHour(int);
		//This will access the hour
		int getHour();
		//This will set the minutes from the user
		void setMinute(std::string);
		//This will access the minute
		std::string getMinute();
		//This will set the what is planned for that time
		void setPlan(std::string);
		//This will get the plan
		std::string getPlan();
		//This will set the day
		void setDay(int);
		//This will set the month
		void setMonth(int);
		//This will set the year
		void setYear(int);
		//This will set the weekday number
		void setDayNumber(int, int, int);
		//These will get the day, month, year, and day numbers
		int getDay();
		int getMonth();
		int getYear();
		int getDayNumber();
};

///////////////////////////////////////////////////////////////////////////////////////

class ScheduleArray
{

	private:

		//This will keep count of the number of schedules
		int currentSchedules;
		//This will be the maximum size of the array
		int maxSchedules;
		//This will create the 2D pointer for the array
		Schedule** PTRarray;

	public:

		//This will create a Dynamic Array
		ScheduleArray();
		//This will destroy the array
		~ScheduleArray();
		//This adds a schedule
		void insertSchedule(int, std::string, std::string, int, int, int);
		//This will display the schedules
		void displaySchedule();
		//This will print a single schedule
		void printSchedule(Schedule*);

};

////////////////////////////////////////////////////////////////////////////////////////////

void Schedule::setHour(int userHour)
{
	//This will set the value of hour
	hour = userHour;
}

//This will set the minute
void Schedule::setMinute(std::string userMin)
{
	//This will set the value of minute
	minute = userMin;
}

//This will set the planned event
void Schedule::setPlan(std::string userPlan)
{
	//This will set the plan
	plan = userPlan;
}

//This sets the numerical day
void Schedule::setDay(int userDay)
{
	//This sets the day
	day = userDay;
}

//This sets the numerical month
void Schedule::setMonth(int userMonth)
{
	//This sets the month
	month = userMonth;
}

//This sets the numerical year
void Schedule::setYear(int userYear)
{
	//This sets the year
	year = userYear;
}

//This sets the day number (weekday)
void Schedule::setDayNumber(int userDay, int userMonth, int userYear)
{
	//This adjusts the month values
	if (userMonth == 1 || userMonth == 2)
	{
		userMonth = userMonth +12;
		userYear = userYear -1;
	}
	//Calculates the day of the week using the Zeller Congruence Algorithm
	daynumber = (userDay + (int)std::floor((13 * (userMonth + 1)) / 5) + (userYear % 100) + (int)std::floor((userYear % 100) / 4) + (int)std::floor(((int)std::floor(userYear / 100)) / 4) + 5 * (int)std::floor(userYear / 7)) % 7;
}	

////////////////////////////////////////////////////////////////////////////////

/*

THINGS TO ADD:

The various get functions
The function that uses daynumber to assign the number to a weekday
(will use a switch statement)
Adding the new values to the older functions

*/

////////////////////////////////////////////////////////////////////////////////

//This accesses the planned event
std::string Schedule::getPlan()
{
	//This gets the planned event
	return plan;
}

//This will access the radius value
int Schedule::getHour()
{
	//This accesses the set hour
	return hour;
}

//This gets the daynumber
int Schedule::getDayNumber()
{
	//Returns the daynumber
	return daynumber;
}

//This gets the day
int Schedule::getDay()
{
	//Returns the day value
	return day;
}

//This gets the month
int Schedule::getMonth()
{
	//Returns the month value
	return month;
}

//This gets the year
int Schedule::getYear()
{
	//Returns the year value
	return year;
}

//This will access the minute value
std::string Schedule::getMinute()
{
	//This accesses the set minute
	return minute;
}

//This will create the dynamic array
ScheduleArray::ScheduleArray()
{
	//This set a max size for the array
	maxSchedules = 10;
	//This sets the current number of schedules
	currentSchedules = 0;
	//This creates the empty array
	PTRarray = new Schedule*[maxSchedules];
}

//This destroys the array
ScheduleArray::~ScheduleArray()
{
	//This deletes the array
	delete [] PTRarray;
}

//This adds values to the array
void ScheduleArray::insertSchedule(int hour, std::string minute, std::string plan, int month, int day, int year)
{
	if (currentSchedules >= maxSchedules)
	{
		//This makes a new max size
		maxSchedules = maxSchedules * 5;
		//This allocates a new array
		Schedule** newArray = new Schedule*[maxSchedules];
		//This copies everything from the old array into the new one
		for (int i=0; i < currentSchedules; i++)
			newArray[i] = PTRarray[i];
		//This points the old name to the new array
		delete [] PTRarray;
		//This deallocates memory for the old array
		PTRarray = newArray;
	}
	//This adds schedules to an array
	PTRarray[currentSchedules] = new Schedule(hour, minute, plan, month, day, year);
	//Increments number of schedules
	currentSchedules++;
}

//This prints a single schedule of the array
void ScheduleArray::printSchedule(Schedule* schedule)
{
	//This points to our needed values
	int hour = schedule -> getHour();
	std::string minute = schedule -> getMinute();
	std::string plan = schedule -> getPlan();
	int month = schedule -> getMonth();
	int day = schedule -> getDay();
	int year = schedule -> getYear();
	int daynumber = schedule -> getDayNumber();
	
	//Creates a weekday string value
	std::string weekday;
	
	switch (daynumber)
	{
            case 2:
		weekday = "Monday";
                break;
            case 3:
		weekday = "Tuesday";
                break;
            case 4:
		weekday = "Wednesday";
                break;
            case 5:
		weekday = "Thursday";
                break;
            case 6:
		weekday = "Friday";
                break;
            case 0:
		weekday = "Saturday";
                break;
            case 1:
		weekday = "Sunday";
                break;
        }

	//This prints out the values if it is 10, 11, or 12
	if (hour >= 10)
	{
		std::cout << weekday << " " << month << " " << day << " " << year << " " <<
			std::setw(2) << std::left << hour << ":" <<
			std::setw(11) << minute << plan << std::endl;
	}
	//This prints out the values if it isn't 10, 11, or 12
	else
	{
		std::cout << weekday << " " << month << " " << day << " " << year << " " <<
			hour << ":" << std::setw(12) << minute
			 << plan << std::endl;
	}
}

//This prints all of the array
void ScheduleArray::displaySchedule()
{
	//This prints out a header for the data
	std::cout << "\n\nSCHEDULE FOR THE DAY\n" << std::endl;

	//This prints out the entire array
	for (int i = 0; i < currentSchedules; i++)
	{
		printSchedule(PTRarray[i]);
	}
}

//This sets the values from the user
Schedule::Schedule( int hour, std::string minute, std::string plan, int month, int day, int year)
{
	//This sets the various values
	setHour(hour);
	setMinute(minute);
	setPlan(plan);
	setMonth(month);
	setDay(day);
	setYear(year);
	setDayNumber(day, month, year);
}

//////////////////////////////////////////////////////////////////////////////

//This creates the menu
void menu();
//This function will get the user's choice as a char for what to do
char menuVal();

void menu()
{
	//These lines will display the menu to the user
	std::cout << std::setw(25) << "\nPress A to enter a schedule time"
			<< std::endl;
	std::cout << std::setw(25) << "Press B to display full schedule"
			<< std::endl;
	std::cout << std::setw(25) << "Press E to exit the program"
			<< std::endl;
	std::cout << std::setw(25) << "Press ? to display this menu again"
			<< std::endl;
}

//This function get's what the user wants to do
char menuVal()
{
	//This variable is the user's input
	char userval;

	//This will ask the user for a char value
	std::cout << std::endl << "Please enter your choice,"
			<< " A, B, E, or ?, capital letters only: ";
	std::cin >> userval;

	//These lines will check if userval is a char between A and E
	while((userval != 'A') && (userval != 'B')
		&& (userval != 'C') && (userval != 'D')
		&& (userval != 'E') && (userval != '?'))
	{
		//This will tell the user to enter a new value
		std::cout << "Invalid entry, please enter a new value"
				<< ", A, B, E, or ?, capital letters only: ";
		std::cin >> userval;
		std::cout << std::endl;
	}

	//Userval has been confirmed as a correct char and will be returned
	return userval;
}

//This function will carry out the program
int main()
{
	//This creates an object of type ScheduleArray
	ScheduleArray arr;

	//This displays the menu
	menu();

	//This is what the user selects from the menu
	char userVal;

	//This executes based on the user's choice
	do
	{
		//This gets the choice
		userVal = menuVal();

		//This creates variables for getting input
		std::string plan;
		int hour, month, day, year;
		std::string minute;
		

		//This switch executes based on choice
		switch(userVal)
		{

			//This case inserts values into the array
			case 'A':
				std::cout << "\nEnter date in mm dd yyyy format: ";
				std::cin >> month >> day >> year;
				std::cout << "\nEnter hour for date: ";
				std::cin >> hour;
				std::cout << "\nEnter minute for date: ";
				std::cin >> minute;
				std::cout << "\nEnter plan for that time: ";
				std::cin.ignore(1000, '\n');	
				std::getline(std::cin, plan);
				//This inputs the schedule
				arr.insertSchedule(hour, minute, plan, month, day, year);
				break;

			//This case displays the schedule
			case 'B':
				//This displays the array
				arr.displaySchedule();
				std::cout << std::endl;
				break;
			//This displays the menu again
			case '?':
				menu();
				break;
			//This exits the program
			case 'E':
				std::cout << "\nProgram will now exit,"
						<< " thanks for the support!"
						<< std::endl;
				break;
		}
	} while(userVal != 'E');

	return 0;
}



