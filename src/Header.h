#pragma once 

enum ArrayIndex {
	ProgramName = 0,
	InputFileName = 1,
	ExpectedArgs = 2,
};

enum ReturnValues {
	Success = 0,
	FileNotFound = 1,
	WrongNumofCommands = 2,
	Failure = 3,
	UnableToRead = 4, 
	IncorrectUsage = 5, 
	InvalidPosition = 6, 
	NoValidPieces = 7,
	IncorrectDimens = 8,
};

ReturnValues usageMessage(const std::string& programName, const std::string& usageInfo);
void becomeLowerCase(std::string& str); 