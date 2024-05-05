#include <iostream>
#include <vector>

#include "block.hpp"

int main() {
    using std::to_string;
    std::cout << "  _   _  ____ _   _    _    ___ _   _ "      << std::endl
              << " | \\ | |/ ___| | | |  / \\  |_ _| \\ | |"   << std::endl
              << " |  \\| | |   | |_| | / _ \\  | ||  \\| |"   << std::endl
              << " | |\\  | |___|  _  |/ ___ \\ | || |\\  |"   << std::endl
              << " |_| \\_|\\____|_| |_/_/   \\_\\___|_| \\_|" << std::endl << std::endl;

    std::cout << "Hello! Enter the difficulty of mining the block: ";
    std::uint32_t difficulty = 5;
    std::cin >> difficulty;
    
    std::cout << "Information: " << std::endl
              << "difficulty:  "  << difficulty << std::endl;
    
	std::cout << "Starting..." << std::endl << std::endl;

	std::vector<nchain::Block> blockChain;
	std::uint32_t blockNumber = 0;

	nchain::Block* tempBlock = new nchain::Block("0", "Genesis");
	blockChain.push_back(*tempBlock);
	std::cout << "Attempting to mine Genesis block..." << std::endl << std::endl;
	blockChain.at(blockNumber).mine_block(difficulty);

	blockChain.at(blockNumber).print_block();
	std::cout << std::endl << std::endl;

	blockNumber++;

	while(1) {
		nchain::Block *nextBlock = new nchain::Block("Block " + to_string(blockNumber), blockChain.at(blockNumber-1).get_hash());
		blockChain.push_back(*nextBlock);
		std::cout << "Attempting to mine next block..." << std::endl << std::endl;
		blockChain.at(blockNumber).mine_block(difficulty);

		blockChain.at(blockNumber).print_block();
        std::uint32_t blockTime = blockChain.at(blockNumber).get_time_stamp() - blockChain.at(blockNumber-1).get_time_stamp();
        std::cout << std::endl << "\tTime to find:  " << blockTime << " seconds" << std::endl << std::endl; 
        
		blockNumber++;
	}

	return 0;
}
