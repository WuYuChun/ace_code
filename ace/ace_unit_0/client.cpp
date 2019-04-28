//
// Created by messi on 19-4-28.
//

#include <ace/Log_Msg.h>
#include "ace/Addr.h"
#include "ace/Init_ACE.h"
#include "ace/INET_Addr.h"
#include "ace/SOCK_Connector.h"

#include "ace/SOCK_Acceptor.h"

int main(int argc ,char *argv[]){
    int ret(0);
    const char *ip = "192.168.3.4";
    short port = 60000;
    ACE_INET_Addr srvr(port,ip);
    ACE_SOCK_Connector connector;
    ACE_SOCK_Stream peer;

    //ACE_Time_Value time(0,500);
    //ret = connector.connect(peer,srvr,&time);
    ret = connector.connect(peer,srvr);
    if(ret == -1){
        ACE_ERROR_RETURN((LM_ERROR,ACE_TEXT("%p\n"),ACE_TEXT("connect")),-1);
    }
    peer.send_n("hello world!",12);
    peer.close();
    return 0;
}