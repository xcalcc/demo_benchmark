#include <exception>
#include <fstream>
#include <string>
 
void file_operation(const std::string &fileName) {
  std::fstream file(fileName);
  if (!file.is_open()) {
    // Handle error
    return;
  }

  FILE *fp_open_readonly = fopen("/tmp/x", "r");

  if (fp_open_readonly != NULL) {
      // writing to the file
      fwrite("HELLO!", 1, 5, fp_open_readonly);
    }

  // ...
  std::terminate();
}

int main()
{
    file_operation("/tmp/tmp.txt");
    return 0;
}
