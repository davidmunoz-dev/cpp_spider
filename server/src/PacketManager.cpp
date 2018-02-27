#include "PacketManager.h"
#include "Data.h"

PacketManager::PacketManager()
{
    size_t i = 0;
    while (i < sizeof(t_packet))
    {
        this->cache[i] = 0;
        i++;
    }
    this->sizeCache = 0;
}

PacketManager::~PacketManager()
{
}

void PacketManager::resetCache()
{
    unsigned int i;

    i = 0;
    while (i < sizeof(t_packet))
    {
        this->cache[i] = 0;
        i++;
    }
    this->sizeCache = 0;
}

void PacketManager::deserializeCache(){
    if (this->sizeCache == sizeof(t_packet)){
        t_packet *p = reinterpret_cast<t_packet *>(this->cache);
        command_.execCmd(command_.findCmd(p->opcode), p);
    }

}
void PacketManager::pushPacket(char *data, size_t sizeData)
{
    if ((sizeData + this->sizeCache) <= sizeof(t_packet))
        {
            size_t i = 0;
            size_t j = this->sizeCache;
            while (i < sizeData && this->sizeCache <= sizeof(t_packet)){
                this->cache[j] = data[i];
                i++;
                j++;
                this->sizeCache++;
            }
            if (this->sizeCache == sizeof(t_packet))
            {
                this->deserializeCache();
                this->resetCache();
            }
        }

        else
        {
            std::cout << "3\n";
            
            size_t i = sizeof(t_packet) - this->sizeCache;

            size_t j = 0;
            size_t k = this->sizeCache;
            while (j < i){
                this->cache[k] = data[j];
                k++;
                j++;
            }
            data += i;
            this->deserializeCache();
            this->resetCache();
            this->pushPacket(data, sizeData - i);
        }

}

void PacketManager::displayPacketList()
{
    std::list<std::string>::iterator it;
    int i = 0;
    for (it = this->serialisedPacket.begin(); it != this->serialisedPacket.end(); it++)
    {
        std::cout << i++ << " " << *it << " size = " << it->size() << std::endl;
    }
}