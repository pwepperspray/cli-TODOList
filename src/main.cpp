#include <iostream>     
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <windows.h>

//function declaration
void list();
void add();
void remove();
void updateState();
void errormsg();

//function definition
void list(const std::string &filePath){
	//file object
	std::ifstream file(filePath, std::ios::in);

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
		std::string stateBuffer;
		std::string state;
		std::stringstream inputString(line);

		getline(inputString, task, ',');
		std::string bufferState = "";
		getline(inputString, stateBuffer,',');
		state = '[' + stateBuffer + ']';
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

void add(const std::string &filePath, std::string task){
	//file operation add
	std::ofstream file(filePath, std::ios::app);

	//writing the task
	file << task //writing the task
	     <<"," //delimiter
	     << " " //writing the state of the task i.e done or not (default is not or -) x == done & - == not
	     <<"\n";
	file.close();

	std::cout << "Added Task!" << "\n";
}

void remove(const std::string &userPath, std::string input){
	/*Since C++ is a what the fuck language to remove a line from a csv file the existing csv file must be
	  copied to a new file while not copying the line you want removed then the newfile with the updated records 
	  is to be renamed as the old file. God I unironically love C++ soo fucking much*/

	std::string newFilePath = userPath + "\\newdata.csv";//path of the new data file
	std::string existingFilePath = userPath + "\\data.csv";	

	//creating file objects	
	std::fstream fileInput;
	std::ofstream fileOutput;
	fileInput.open(existingFilePath, std::ios::in); //open existing file
	if(!fileInput.is_open()){
		std::cerr << "Error data file couldnt be opened \n";//checking if file opened succesfully
	}

	//initializing variables that will need for copying
	int index = std::stoi(input);
	int i = 1;
	std::string line;

	//checking if existing file is empty
	fileInput.seekg(0,std::ios::end);
	if(fileInput.tellg() < 1){
		std::cout << "No tasks to delete \n";//if tasks empty
		fileInput.close();
	}
	else{
		//when task isnt empty
		fileInput.clear();
		fileInput.seekg(0, std::ios::beg);

		//creating the new file to copy the data into
		fileOutput.open(newFilePath, std::ios::out);
		//copying the contents into the newfile
		while(std::getline(fileInput, line)){
			if(i != index){
			fileOutput << line << "\n";
			}
			line.clear();
			i++;
		}
		fileInput.close();
		fileOutput.close();

		//deleting the existing file and renaming the updated file as the existing one
		int checkRemove = remove(existingFilePath.c_str());
		int checkRename = rename(newFilePath.c_str(), existingFilePath.c_str());

		if(checkRemove == 0 && checkRename == 0){
			std::cout << "Task Removed! \n";
		}
		else{
			std::cout << "Shit happened. something wrong \n";
		}

	}
}

void updateState(const std::string &userPath, std::string input, std::string state){
	std::string newFilePath = userPath + "\\newdata.csv";//path of the new data file
	std::string existingFilePath = userPath + "\\data.csv";	

	//creating file objects	
	std::fstream fileInput;
	std::ofstream fileOutput;
	
	fileInput.open(existingFilePath, std::ios::in); //open existing file
	if(!fileInput.is_open()){
		std::cerr << "Error data file couldnt be opened \n";//checking if file opened succesfully
	}

	//initializing variables that will need for copying
	int index = std::stoi(input);
	int i = 1;
	std::string line;
	
	//checking if existing file is empty
	fileInput.seekg(0,std::ios::end);
	if(fileInput.tellg() < 1){
		std::cout << "No tasks to update \n";//if tasks empty
		fileInput.close();
	}
	else{
		//when task isnt empty
		fileInput.clear();
		fileInput.seekg(0, std::ios::beg);

		//creating the new file to copy the data into
		fileOutput.open(newFilePath, std::ios::out);
		
		//copying the contents into the newfile
		while(std::getline(fileInput,line)){
			if(i == index){
				//updating state here
				std::stringstream inputString(line);
				std::string task;
				
				std::getline(inputString,task,',');
				if (state == "True" || state == "true"){
					fileOutput << task
							   << ","
							   << "x"
							   <<"\n";
				}
				else if (state == "False" || state == "false"){
					fileOutput << task
							   << ","
							   << " "
							   << "\n";
				}
				line.clear();
			}
			else{
				fileOutput << line << "\n";
			}
			line.clear();
			i++;
			
		}
		
		fileInput.close();
		fileOutput.close();

		//deleting the existing file and renaming the updated file as the existing one
		int checkRemove = remove(existingFilePath.c_str());
		int checkRename = rename(newFilePath.c_str(), existingFilePath.c_str());

		if(checkRemove == 0 && checkRename == 0){
			std::cout << "Task state Updated! \n";
		}
		else{
			std::cout << "Shit happened. something wrong \n";
		}

	}
	
}

void errormsg(){
	std::cout << "ERROR! dk what error lazy to write specific error msg maybe later \n";
}

//main 
int main (int argc, char* argv[]) {

	//finding the user profile path and saving it
	char * userPath = std::getenv("USERPROFILE");
	std::string path;
	if (userPath != nullptr){
		path =  std::string(userPath) + "\\data.csv"; 
	}

	//chekcing if the file exists and creating one if it doesnt
	std::ifstream file(path);
	if(!file){
		std::ofstream createFile(path);
		createFile.close();
	}
	file.close();
	

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
		remove(userPath, argument[2]);
	}
	else if (argument[1] == "state"){
		updateState(userPath, argument[2], argument[3]);
	}


	return 0;
}
