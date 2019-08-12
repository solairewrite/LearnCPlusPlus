#include <string>
#include <fstream>   // for ofstream
#include <memory>    // for shared_ptr
#include <cstdio>    // for remove()

class FileDeleter
{
  private:
    std::string filename;
  public:
    FileDeleter (const std::string& fn)
     : filename(fn) {
    }
	// ��������
    void operator () (std::ofstream* fp) {
        delete fp;                     // close file
        std::remove(filename.c_str()); // delete file
    }
};

int main()
{
    // create and open temporary file:
	// �����д���txt: echo "abc" > tmpfile.txt
    std::shared_ptr<std::ofstream> fp(new std::ofstream("tmpfile.txt"),
                                      FileDeleter("tmpfile.txt"));
    //...
}
