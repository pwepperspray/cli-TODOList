#include <iostream>     
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

//function declaration
void list();
void add();
void remove();
void updateState();
void errormsg();

//function definition
void list(const std::string &filepath){
	//file object
	std::ifstream file(filepath, std::ios::in);

	//Table formatting	
	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(3) << "-" << std::setw(1) << "+" 
	 	  << std::setw(100) << "-" << std::setw(1) << "+" << std::setw(5) << "-" 
		  << std::setw(1) << "+" << std::endl; //Table top border
								 
	std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(3) << std::left << "No."
		  << std::setw(1) << "|" << std::setw(50) << std::right << "Tasks" << std::setw(51) << std::right << "|"
		  << std::setw(5) << std::left << "State" << std::setw(1) << "|" << std::endl; //Table column names

	std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(3) << "-" << std::setw(1) << "+" 
		  << std::setw(100) << "-" << std::setw(1) << "+" << std::setw(5) << "-" 
		  << std::setw(1) << "+" << std::endl;//Table low border


	std::string line = "";
	int i = 1;
	while(getline(file, line)){
		std::string task;
		std::string statebuffer;
		std::string state;
		std::stringstream inputString(line);

		getline(inputString, task, ',');
		std::string bufferState = "";
		getline(inputString, statebuffer,',');
		state = '[' + statebuffer + ']';
		//state = atoi(bufferState.c_str());
		line = "";
		
		//displaying the data in a tabular form
		std::cout << std::setfill(' ') << std::setw(1) << "|" << std::setw(3) << std::left << i << std::setw(1) << "|"
			  << std::setw(100) << std::left << task << std::setw(1) << std::right << "|" 
			  << std::setw(5) << std::left << state << std::setw(1) << "|" << std::endl;

		std::cout << std::setfill('-') << std::setw(1) << "+" << std::setw(3) << "-" << std::setw(1) << "+"
			  << std::setw(100) << "-" << std::setw(1) << "+" << std::setw(5) << "-" 
			  << std::setw(1) << "+" << std::endl;
		i++;
	}
	file.close();
}

void add(const std::string &filepath, std::string task){
	//file operation add
	std::ofstream file(filepath, std::ios::app);

	//writing the task
	file << task //writing the task
	     <<"," //delimiter
	     << " " //writing the state of the task i.e done or not (default is not or -) x == done & - == not
	     <<"\n";
	file.close();

	std::cout << "Added Task!" << "\n";
}

void remove(const std::string &filepath, std::string input){

	int index = std::stoi(input);
	int i = 0;
	while (i < index){
		
		i++;
	}
}

void updateState(){
	std::cout << "bored \n";
}

void errormsg(){
	std::cout << "ERROR! dk what error lazy to write specific error msg maybe later \n";
}

//main 
int main (int argc, char* argv[]) {

	//finding the user profile path and saving it
	char * userpath = std::getenv("USERPROFILE");
	std::string path;
	if (userpath != nullptr){
		path =  std::string(userpath) + "\\data.csv"; 
	}

	//chekcing if the file exists and creating one if it doesnt
	std::ifstream file(path);
	if(!file){
		std::ofstream createfile(path);
		createfile.close();
	}
	

	//initialization of array containing argument variables
	//inserting the arguments into an array
	std::string argument[4] = {}; 
	if (argc < 2){
		errormsg();
	}
	else{
		for(int i = 0; i < argc; i++){
			argument[i] = argv[i];
		}
	}
	
	//checking the commmand line arguments and working accordingly
	//list the todo list
	if(argument[1] == "list"){
		list(path);
	}
	//add a new task
	else if (argument[1] == "add"){
		add(path, argument[2]);
	}
	//remove a task
	else if (argument[1] == "rm"){
		remove(path, argument[2]);
	}


	return 0;
}
