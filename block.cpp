#include "block.hpp"
#include "sha256.h"
#include <ctime>
#include <vector>
#include <iostream>

using std::to_string;

nchain::Block::Block(const std::string& previousHash, const std::string& data) {
	this->data = data;
	this->previousHash = previousHash;
	this->timeStamp = time(0);
	this->hash = calculate_hash();
}

nchain::Block::~Block() {}

std::string nchain::Block::calculate_hash() {
	std::string calculatedHash = sha256(previousHash + to_string(timeStamp) + to_string(nonce) + data);
	return calculatedHash;
}



void nchain::Block::mine_block(unsigned difficulty){
	std::string target = "";
	for (unsigned i = 0; i < difficulty; i++) target.append("0");
	while(hash.substr(0, difficulty) != target){
		nonce++;
		hash = calculate_hash();
	}

	std::cout << "Block found!";
}

void nchain::Block::print_block() {
    std::cout << "\n\tHash:          " << get_hash() 
	          << "\n\tPrevious Hash: " << get_previous_hash()
	          << "\n\tNonce:         " << get_nonce() 
	          << "\n\tTimeStamp:     " << get_time_stamp() 
	          << "\n\tData:          " << get_data();
}
