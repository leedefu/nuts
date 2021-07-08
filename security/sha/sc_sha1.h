# ifndef SC_SHA1_H
#define SC_SHA1_H

namespace security
{

class sc_sha1
{
public:
    sc_sha1();
    ~sc_sha1();

public:
    // return true : ok
    //        false: failure
    // 
    // attention: caller need to release output memory, output memory is char array.(delete [])
    bool do_sha1(const char* input, unsigned int input_size, unsigned char** output, unsigned int& output_size);

private:
    // no copy
    sc_sha1(const sc_sha1&);
    sc_sha1& operator=(const sc_sha1&);

}; // class sc_sha1

} // namespace security

#endif // SC_SHA1_H
