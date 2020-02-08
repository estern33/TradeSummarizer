#include <fstream>
#include <iostream>
#include "gtest/gtest.h"
#include "trade_stream_parser.h"

using namespace std;

namespace {

TEST(TradeStreamParser, SampleFileYieldsCorrectOutput) {

    // Write the sample csv text to a file within the build directory,
    // parse it, write out the output and compare to expected.
    ofstream output_file;
    output_file.open("sample.csv");

    output_file << "52924702,aaa,13,1136\r" << endl;
    output_file << "52924702,aac,20,477\r" << endl;
    output_file << "52925641,aab,31,907\r" << endl;
    output_file << "52927350,aab,29,724\r" << endl;
    output_file << "52927783,aac,21,638\r" << endl;
    output_file << "52930489,aaa,18,1222\r" << endl;
    output_file << "52931654,aaa,9,1077\r" << endl;
    output_file << "52933453,aab,9,756";

    output_file.close();

    tradesummarizer::TradeStreamParser("sample.csv").WriteResult("sample_output.csv");

    ifstream input_file("sample_output.csv");
    string line;
    getline(input_file, line);
    ASSERT_EQ(line, "aaa,5787,40,1161,1222");
    getline(input_file, line);
    ASSERT_EQ(line, "aab,6103,69,810,907");
    getline(input_file, line);
    ASSERT_EQ(line, "aac,3081,41,559,638");
    getline(input_file, line);
    ASSERT_EQ(input_file.eof(), true);
}

}  // namespace