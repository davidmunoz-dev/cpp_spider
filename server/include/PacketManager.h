#ifndef PACKETMANAGER_H_
#define PACKETMANAGER_H_

#include <iostream>
#include <list>
#include "Data.h"
#include "CommandInput.h"
class PacketManager
{

  public:
    PacketManager();
    ~PacketManager();
    void                    pushPacket(char *data, size_t size);
    void                    pushOnePacket(char *data);
    void                    displayPacketList();
    void                    resetCache();
    void                    deserializeCache();

    std::list<std::string>  serialisedPacket;

    char                    cache[sizeof(t_packet)];
    size_t                  sizeCache;
    CommandInput	          command_;
};
#endif /* ! PACKETMANAGER_H_ */