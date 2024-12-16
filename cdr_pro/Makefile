# Compiler and Flagsi

CC = gcc

CFLAGS = -Wall -g

INCLUDE_FLAGS = -I./inc
 
# Directories

SRC_DIR = ./src

OBJ_DIR = ./obj

BIN_DIR =./bin

DATA_DIR = ./data
 
# Source and Object Files

SRC_FILES = $(SRC_DIR)/server.c $(SRC_DIR)/client.c $(SRC_DIR)/logIn.c $(SRC_DIR)/signUp.c $(SRC_DIR)/customerBilling.c $(SRC_DIR)/interOperatorBilling.c $(SRC_DIR)/dataProcess.c

OBJ_FILES = $(OBJ_DIR)/server.o $(OBJ_DIR)/client.o $(OBJ_DIR)/logIn.o $(OBJ_DIR)/signUp.o $(OBJ_DIR)/customerBilling.o $(OBJ_DIR)/interOperatorBilling.o $(OBJ_DIR)/dataProcess.o
 
# Targets

$(BIN_DIR)/server: $(OBJ_DIR)/server.o $(OBJ_DIR)/logIn.o $(OBJ_DIR)/signUp.o $(OBJ_DIR)/customerBilling.o $(OBJ_DIR)/interOperatorBilling.o $(OBJ_DIR)/dataProcess.o

	$(CC) $(OBJ_DIR)/server.o $(OBJ_DIR)/logIn.o $(OBJ_DIR)/signUp.o $(OBJ_DIR)/customerBilling.o $(OBJ_DIR)/interOperatorBilling.o $(OBJ_DIR)/dataProcess.o -o $(BIN_DIR)/server -pthread
 
$(BIN_DIR)/client: $(OBJ_DIR)/client.o $(OBJ_DIR)/logIn.o $(OBJ_DIR)/signUp.o

	$(CC) $(OBJ_DIR)/client.o $(OBJ_DIR)/logIn.o $(OBJ_DIR)/signUp.o -o $(BIN_DIR)/client
 
# Compilation Rules

$(OBJ_DIR)/server.o: $(SRC_DIR)/server.c

	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $(SRC_DIR)/server.c -o $(OBJ_DIR)/server.o
 
$(OBJ_DIR)/client.o: $(SRC_DIR)/client.c

	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $(SRC_DIR)/client.c -o $(OBJ_DIR)/client.o
 
$(OBJ_DIR)/logIn.o: $(SRC_DIR)/logIn.c

	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $(SRC_DIR)/logIn.c -o $(OBJ_DIR)/logIn.o
 
$(OBJ_DIR)/signUp.o: $(SRC_DIR)/signUp.c

	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $(SRC_DIR)/signUp.c -o $(OBJ_DIR)/signUp.o
 
$(OBJ_DIR)/customerBilling.o: $(SRC_DIR)/customerBilling.c

	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $(SRC_DIR)/customerBilling.c -o $(OBJ_DIR)/customerBilling.o
 
$(OBJ_DIR)/interoperatorbilling.o: $(SRC_DIR)/interOperatorBilling.c

	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $(SRC_DIR)/interOperatorBilling.c -o $(OBJ_DIR)/interOperatorBilling.o
 
$(OBJ_DIR)/customerDataProcess.o: $(SRC_DIR)/dataProcess.c

	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $(SRC_DIR)/dataProcess.c -o $(OBJ_DIR)/dataProcess.o
 
# Clean up

clean:

	@echo "Cleaning up object and binary files..."

	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*
 
# Create necessary directories

 
# Default target

all: $(BIN_DIR) $(OBJ_DIR) $(BIN_DIR)/server $(BIN_DIR)/client

 
