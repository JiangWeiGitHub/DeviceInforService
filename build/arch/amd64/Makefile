CC = 						gcc
RM = 						rm
RES =						mininas_as
OBJ = 						../../../source/Main.o ../../../source/DeviceInforService.o ../../../source/order.o
INCLUDE_PATH= 				../../../header
CFLAGS  =                   -g -Wall
LIB_NAME =                  mininas_as.so
ALL_INTERFACE = 			
LIB_PATH_NAME = 		
LIB_INCLUDE_NAME = 			
all: $(OBJ)
	$(CC) $(OBJ) -o $(RES) $(CFLAGS) -I $(INCLUDE_PATH)
	$(CC) -shared -o $(LIB_NAME) $(OBJ) $(CFLAGS) -I $(INCLUDE_PATH)
	$(RM) $(OBJ)
	@echo "make finished."
$(OBJ):../../../source/%.o : ../../../source/%.c
	$(CC) -fPIC -c $^ -o $@ -I $(INCLUDE_PATH)
		    
#.PHONY: clean
clean:
	$(RM)  $(RES) $(LIB_NAME)
