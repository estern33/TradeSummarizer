#include <iostream>

using namespace std;

// General Notes and Assumptions:
// - Attempting to follow Google's C++ style guide: https://google.github.io/styleguide/cppguide.html
// - Due to lack of a logging framework in this small project, all messages I would normally log are written to standard output.
// - Assuming quantity, like price, is a round number greater than zero, and enforcing as much in quantity at price.
// - Assuming 0 is an acceptable WeightedAveragePrice if no trades is received.  Realistically, the program would not process a VWAP for a file that had no trades anyway.
// - Assuming that even if the source data were from a networked file far larger than the local disk or memory, or from an entirely different method of input and output streaming,
//   the summarized data per symbol will fit in memory.

// Uses classes provided in TradeSummarizer to ingest trades from input.csv and write a summary to output.csv.
// The input file is expected to be in the same directory as the executable.  The output file will be written to the same directory.
// This main uses file streams to read and record results to local file, but the system is intended to be able to work with remote file systems or any other stream implementation.
// Program returns 0 if trades were successfully summarized, -1 otherwise.
int main() {
    try {

    }
    catch (exception &e) {
        // Wish I could find a good method for string interpolation a la python.  Did not come across anything on first glace.
        // I see std::format coming in C++20.  Hope missing parameters are caught at compile time, this was always a headache in Java.
        // If I were spending more time, I would consider other options, like a format library or the sstr function in this SO post https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c.
        // This is true for the cout below and many of the the exception strings generated in the project.
        cout << "Exception caught in main: " << e.what() << "\n";
        return -1;
    }

    cout << "Input file successfully processed.  Check output.csv for results." << endl;
    return 0;
}