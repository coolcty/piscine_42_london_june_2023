#!/bin/sh

# 1. Compile the program
make re

# 2. Create test files
echo "FADF
Acronym	Definition
FADF	Federação de Automobilismo do Distrito Federal (Portuguese: Automobile Federation of the Federal District; Brazil)
FADF	Filipino-American Development Foundation (San Francisco, CA)
FADF	Fédération des Associations Domoniennes en France (French: Federation of Associations in France Domoniennes)
FADF	Fédération des Associations Djiboutiennes en France (French: Federation of Djibouti in France)
FADF	Florida African Dance Festival
FADF	Fleet Air Defense Fighter (US Navy)
Copyright 1988-2018 AcronymFinder.com, All rights reserved.
Suggest new definition


Want to thank TFD for its existence? Tell a friend about us, add a link to this page, or visit the webmaster's page for free fun content." > test1.txt
echo "This is another test file." > test2.txt

# 3. Test: No argument
echo "--- Expect: File name missing. ---"
./ft_display_file

# 4. Test: More than one argument
echo "--- Expect: Too many arguments. ---"
./ft_display_file test1.txt test2.txt

# 5. Test: Single argument, file exists
echo "--- Expect: Contents of test1.txt ---"
./ft_display_file test1.txt

# 6. Test: Single argument, file does not exist
echo "--- Expect: Cannot read file. ---"
./ft_display_file non_existent_file.txt

# 7. Clean up
rm test1.txt
rm test2.txt
make fclean
