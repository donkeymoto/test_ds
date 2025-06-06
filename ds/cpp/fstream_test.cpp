#include <iostream>
#include <fstream>
#include <vector>

int main(void)
{
	int dataSize = 0x10;
	uint8_t dataPat = 0xaa;
	char *fname = "fstream_test.bin";

	std::vector<uint8_t> vecData(dataSize, dataPat);
	std::ofstream os(fname, std::ios_base::binary);
	os.write(reinterpret_cast<char *>(&vecData[0]), vecData.size());
	os.close();


	std::vector<uint8_t> dataOut(dataSize);
	std::ifstream is(fname, std::ios_base::binary);
	is.seekg(0, std::ios_base::end);
	uint32_t len = is.tellg();
	is.seekg(0, std::ios_base::beg);
	std::cout << "File size is: "
						<< len
						<< " bytes"
						<< std::endl;


	is.read(reinterpret_cast<char *>(&dataOut[0]), dataSize);

}
