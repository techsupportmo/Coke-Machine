#ifndef COKE_LIB_H
#define COKE_LIB_H

#include <iostream>
#include <vector>

bool ParseCokeLine(const std::string& CokeMachineLine, std::vector<std::string>& params);
void get_command_line_params(int argc, char *argv[], std::string& InputFileName, std::string& OutputFileName);

#endif
