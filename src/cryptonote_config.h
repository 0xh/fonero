// Copyright (c) 2017-2018, The Fonero Project.
// Copyright (c) 2014-2017 The Monero Project.
// Portions Copyright (c) 2012-2013 The Cryptonote developers.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#pragma once

#include <string>
#include <boost/uuid/uuid.hpp>

#define CRYPTONOTE_DNS_TIMEOUT_MS								20000
#define CRYPTONOTE_MAX_BLOCK_NUMBER							500000000
#define CRYPTONOTE_MAX_BLOCK_SIZE								500000000
#define CRYPTONOTE_MAX_TX_SIZE								1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_TEXTBLOB_VER					0
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW					60
#define CURRENT_TRANSACTION_VERSION							1
#define CURRENT_BLOCK_MAJOR_VERSION							1
#define CURRENT_BLOCK_MINOR_VERSION							1
#define CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE						10
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT						60*24
#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW						12
#define MONEY_SUPPLY										((uint64_t)(-1))
#define EMISSION_SPEED_FACTOR_PER_MINUTE							(20)
#define FINAL_SUBSIDY_PER_MINUTE								((uint64_t)300000000000)
#define DEVELOPER_BLOCKS_REWARD								((uint64_t)2000000000000000000)
#define DEVELOPER_BLOCKS_COUNT								1
#define CRYPTONOTE_REWARD_BLOCKS_WINDOW						100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1				60000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2				300000
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE					600
#define CRYPTONOTE_DISPLAY_DECIMAL_POINT						12
#define COIN												((uint64_t)1000000000000)
#define DEFAULT_MIXIN										12
#define DEFAULT_RINGSIZE										(DEFAULT_MIXIN + 1)
#define DYNAMIC_FEE_PER_KB_BASE_FEE								((uint64_t)400000000)
#define DYNAMIC_FEE_PER_KB_BASE_BLOCK_REWARD					((uint64_t)10000000000000)
#define DIFFICULTY_TARGET										120
#define DIFFICULTY_WINDOW									720
#define DIFFICULTY_LAG										15
#define DIFFICULTY_CUT										6
#define DIFFICULTY_BLOCKS_COUNT								DIFFICULTY_WINDOW + DIFFICULTY_CUT * 2
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS				DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS				1
#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT					10000
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT						20
#define CRYPTONOTE_PROTOCOL_HOP_RELAX_COUNT					3
#define CRYPTONOTE_MEMPOOL_TX_LIVETIME							86400
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME			604800
#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT					1000
#define P2P_LOCAL_WHITE_PEERLIST_LIMIT							1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT							5000
#define P2P_DEFAULT_CONNECTIONS_COUNT							8
#define P2P_DEFAULT_HANDSHAKE_INTERVAL							60
#define P2P_DEFAULT_PACKET_MAX_SIZE								50000000
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE							250
#define P2P_DEFAULT_CONNECTION_TIMEOUT							5000
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT						2000
#define P2P_DEFAULT_INVOKE_TIMEOUT								60*2*1000
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT					5000
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT				70
#define P2P_DEFAULT_ANCHOR_CONNECTIONS_COUNT					2
#define P2P_FAILED_ADDR_FORGET_SECONDS							(60*60)
#define P2P_IP_BLOCKTIME										(60*60*24)
#define P2P_IP_FAILS_BEFORE_BLOCK								10
#define P2P_IDLE_CONNECTION_KILL_INTERVAL						(5*60)
#define P2P_SUPPORT_FLAG_FLUFFY_BLOCKS							0x01
#define P2P_SUPPORT_FLAGS										P2P_SUPPORT_FLAG_FLUFFY_BLOCKS
#define ALLOW_DEBUG_COMMANDS
#define CRYPTONOTE_NAME										"fonero"
#define CRYPTONOTE_POOLDATA_FILENAME							"poolstate.bin"
#define CRYPTONOTE_BLOCKCHAINDATA_FILENAME						"data.mdb"
#define CRYPTONOTE_BLOCKCHAINDATA_LOCK_FILENAME					"lock.mdb"
#define P2P_NET_DATA_FILENAME									"p2pstate.bin"
#define MINER_CONFIG_FILE_NAME									"miner_conf.json"
#define THREAD_STACK_SIZE										5 * 1024 * 1024
#define PER_KB_FEE_QUANTIZATION_DECIMALS						8

namespace config
{
  std::string const P2P_REMOTE_DEBUG_TRUSTED_PUB_KEY = "0000000000000000000000000000000000000000000000000000000000000000";
  uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 47;
  uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 48;
  uint16_t const P2P_DEFAULT_PORT = 18180;
  uint16_t const RPC_DEFAULT_PORT = 18181;

  boost::uuids::uuid const NETWORK_ID = { { 0x15 ,0x36, 0xF2, 0x41 , 0x64, 0x42 , 0x63, 0x74, 0x12, 0x46, 0x86, 0x51, 0x25, 0xA3, 0xA1, 0x17 } };
  std::string const GENESIS_TX = "013c01ff0001ffffffffffff07029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101a13fb9f21e6840fbc6a5db6416e3f3597ff8236131ecebb573a19546a536217100";
  uint32_t const GENESIS_NONCE = 10000;
  namespace testnet {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 77;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 87;
    uint16_t const P2P_DEFAULT_PORT = 28180;
    uint16_t const RPC_DEFAULT_PORT = 28181;
    boost::uuids::uuid const NETWORK_ID = { { 0x15 ,0x36, 0xF2, 0x41 , 0x64, 0x42 , 0x63, 0x74, 0x12, 0x46, 0x86, 0x51, 0x25, 0xA3, 0xA1, 0x18 } };
    std::string const GENESIS_TX = "013c01ff0001ffffffffffff07029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121013777721748bbae12a78143a3702c0832256f2223a52a3c97ca539035ae7167b800";
    uint32_t const GENESIS_NONCE = 10001;
  }
}
