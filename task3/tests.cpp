#include "gtest/gtest.h"

#include "base64.h"
TEST(Encode, EncodeStr)
{
	std::string s ="DEV";
	 std::ostringstream out;
	encode(s,out);
	
	EXPECT_EQ(out.str(), "REVW");
}
TEST(DEcode, DEcodeStr)
{
        std::string s ="SQ==";
         std::ostringstream out;
        base64_decode(s,out);

        EXPECT_EQ(out.str(), "I");
}
TEST(Translate, CodeChar)
{
        
         std::ostringstream out;
       

        EXPECT_EQ(FullandString(111,8), "00000111");
}
TEST(Encode2, EncodeStr2)
{
        std::string s ="MAN";
         std::ostringstream out;
        encode(s,out);

        EXPECT_EQ(out.str(), "TUFO");
}
TEST(DEcode2, DEcodeStr2)
{
        std::string s ="TkFOTw==";
         std::ostringstream out;
        base64_decode(s,out);

        EXPECT_EQ(out.str(), "NANO");
}
TEST(Encode3, EncodeStr3)
{
        std::string s ="";
         std::ostringstream out;
        encode(s,out);

        EXPECT_EQ(out.str(), "");
}
TEST(DEcode3, DEcodeStr3)
{
        std::string s ="";
         std::ostringstream out;
        base64_decode(s,out);

        EXPECT_EQ(out.str(), "");
}

