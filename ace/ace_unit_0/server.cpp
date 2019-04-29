//
// Created by messi on 19-4-28.
//
#include <ace/Log_Msg.h>
#include "ace/Addr.h"
#include "ace/Init_ACE.h"
#include "ace/INET_Addr.h"

#include "ace/SOCK_Acceptor.h"

#include "ace/IPC_SAP.h"


int main(int argc ,char *argv[]){

    ACE_INET_Addr port_to_listen(60000);
    ACE_SOCK_Acceptor acceptor;

    if(acceptor.open(port_to_listen,1) == -1){
        ACE_ERROR_RETURN((LM_ERROR,ACE_TEXT("%p\n"),ACE_TEXT("acceptor.open")),-1);
    }

    while(1){
        ACE_SOCK_Stream peer;
        ACE_INET_Addr peer_addr;

        if(acceptor.accept(peer,&peer_addr) == -1){
            ACE_DEBUG((LM_DEBUG,ACE_TEXT("accept errer\n")));
        }
        else{
            ACE_TCHAR peer_name[MAXHOSTNAMELEN];
            peer_addr.addr_to_string(peer_name,MAXHOSTNAMELEN);
            ACE_DEBUG((LM_DEBUG,ACE_TEXT("Connetion from %s\n"),peer_name));
            char buffer[4096];
            size_t bytes_received;

            while((bytes_received = peer.recv(buffer, sizeof(buffer))) > 0){
                buffer[bytes_received]=0;
                ACE_DEBUG((LM_DEBUG,ACE_TEXT("receiver data:%s\n"),buffer));
            }
            peer.close();
            ACE_DEBUG((LM_DEBUG,ACE_TEXT("close the socket.\n")));
        }
    }
    ACE_NOTREACHED(return  0);
}