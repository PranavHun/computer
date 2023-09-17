add_library(computer STATIC transistor.c gates.c alu.c)
install(TARGETS computer LIBRARY DESTINATION lib/)
