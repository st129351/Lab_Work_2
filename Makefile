CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -pthread -I. -Werror -Wpedantic
CXX_FLAG = -Iinclude
GTEST_LIBS = -lgtest -lgtest_main -lpthread

SRC_DIR = src
# wildcard - satisfies the pattern 
PROJ_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(PROJ_FILES:.cpp=.o)

TEST_DIR = gtests
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES = $(TEST_FILES:.cpp=.o)

# Exclude main.o from object files
OBJ_FILES_WITHOUT_MAIN = $(filter-out $(SRC_DIR)/main.o, $(OBJ_FILES))

EXE_1 = labwork2
EXE_2 = tests

all: $(EXE_1) $(EXE_2)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CXX_FLAG) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CXX_FLAG) -c $< -o $@

# executables
$(EXE_1): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(CXX_FLAG) $^ -o $@

# instead of $^ I can use "$(OBJ_FILES) $(TEST_OBJ_FILES) "
# instead of #@ I can use "main"
$(EXE_2): $(OBJ_FILES_WITHOUT_MAIN) $(TEST_OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(CXX_FLAG) $^ $(GTEST_LIBS) -o $@

# "*" - for terminal, "%" - for Makefile
clean:
	rm -f $(TEST_DIR)/*.o $(SRC_DIR)/*.o

cleanall:
	rm -f $(TEST_DIR)/*.o $(SRC_DIR)/*.o $(EXE_1) $(EXE_2)