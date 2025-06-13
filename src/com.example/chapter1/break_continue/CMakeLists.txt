add_executable(break_continue BreakContinue.c)

#CMake Error at CMakeLists.txt
#add_library cannot create target “xxx” because another target with the same name already exists. The existing target is an executable created in source directory “/root/xxx/xxx”.See documentation for policy CMP0002 for more details.
#在使用cmake进行编译时出现上述问题，最大的可能是编译生成的应用程序名称和生成的库文件名称是一样而导致的错误。所以需要检查add_executable内的程序名称和add_library的库文件名称。库文件的名称一般来说不与应用程序名称相同。修改后可能可解决上述问题
#————————————————
