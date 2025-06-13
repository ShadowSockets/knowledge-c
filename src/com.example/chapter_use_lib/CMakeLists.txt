add_executable(chapter_use_lib UseLib.c)


#静态库链接用法(公司电脑和家用电脑环境不一样)
#target_link_libraries(chapter_use_lib C:\\Users\\sxh\\CLionProjects\\c-college\\src\\com.example\\chapter_use_lib\\GenerateLib.lib)
target_link_libraries(chapter_use_lib G:\\workstation\\knowledge-c\\src\\com.example\\chapter_use_lib\\GenerateLib.lib)