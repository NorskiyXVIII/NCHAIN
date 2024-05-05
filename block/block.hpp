#ifndef BLOCK_HPP_USED
#define BLOCK_HPP_USED

#include <cstdint>
#include <climits>
#include <ctime>

#include <string>


namespace nchain {
    class Block {
    private:
    	std::string hash;
    	std::string previousHash;
    	std::string data;
    	std::uint32_t nonce;
    	std::int64_t timeStamp;
    public:
    	Block(const std::string& previousHash, const std::string& data);
    	~Block();

    	std::string   calculate_hash();
    	std::string   get_previous_hash() { return this->previousHash; }
    	std::string   get_hash()          { return this->hash; }
    	std::uint32_t get_nonce()         { return this->nonce; }
    	std::string   get_data()          { return this->data; }
    	std::int64_t  get_time_stamp()    { return this->timeStamp; }
    	
    	void mine_block(std::uint32_t difficulty);
    	void print_block();

    };
}

#endif
