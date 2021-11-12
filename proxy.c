#include <stdio.h>
#include "csapp.h"  
#include "cache.h"

//prototypes for functions defined and used in this file
static void handleRequest(int connfd);
static void getRequest(int connfd, char * method, char * uri, 
                       char * version, char * host);
static int isValid(char * method, char * version);
static void parseURI(char * uri, char * host, char * path, char * port);
static void getPort(char * port, char * str);
static void getPath(char * port, char * str);
static void getHost(char * port, char * str);
static void makeRequest(int connfd, char * uri, char * request, 
                        char * host, char * port);
static void buildRequest(char * request, char * host,
                         char * path, char * version);

//
// Create a listening socket. Accept connection requests on
// the listening socket.  Read one request from the connected
// socket, respond to it, and close the socket.
//
// Helpful code: main in tiny.c
//
int main(int argc, char **argv)
{
   return 1;
}

// handleRequest
// Reads the request from the connected socket by calling getRequest.
// If the method or version isn't valid, the function returns
// without doing anything.
//
// Otherwise, it checks to see if the item is cached. 
// If it is, the item is written to the connected socket.  
// If it is not, it parses the uri to get the host, the path 
// to the file, and the port. Then, it builds the
// request. Finally, it sends the request, gets the response, 
// sends the response to the connected socket, and potentially 
// caches the response.
//
// Helper functions: getRequest, isValid, findCacheItem, 
//                   Rio_writen (for writing object from cache),
//                   parseURI, buildRequest, makeRequest
void handleRequest(int connfd)
{
   char method[MAXLINE];  //first word on request line, such as GET
   char uri[MAXLINE];     //uri on the request line
   char version[MAXLINE]; //version on the request line, such as HTTP/1.1
   char port[MAXLINE];    //port obtained from the request line or 80 
   char host[MAXLINE];    //host from the HOST: header or from the uri if no header
   char path[MAXLINE];    //path to table obtained from the request line
   char request[MAXBUF];  //request to send to origin server

   return;
}

// buildRequest
// Build the request to send to the origin server.
// The request needs to have the: 
//    1) request line (GET path version)
//    2) Host: header line
//    3) User-Agent: header line
//    4) Connection: close
//    5) Proxy-Connection: close
//
// Helpful code: serve_static in tiny.c (note its use of sprintf)
void buildRequest(char * request, char * host, char * path, char * version)
{
   char *userAgentHdr = "Mozilla/5.0 (X11; Linux x86_64; rv:10.0.3) Gecko/20120305 Firefox/10.0.3";
   return;
}

// makeRequest
// This function connects to the origin server.
// If the open succeeds, the request is written to the socket.
// After that, the response from the origin server is read in
// a loop and sent to the client via the connected socket.
//
// In addition, space (MAX_OBJECT_SIZE bytes) is dynamically allocated 
// to hold the object using the function Calloc.
// The response from the  origin server is copied (piece by piece) into the dynamically 
// allocated space using a memcpy.  (memcpy needs to be used instead of
// strcpy because the object might be binary.) If the object isn't too big,
// it is added to the cache.  If it is too big, the dynamically
// allocated space is freed.
//
// Helper functions: Calloc, Open_clientfd, Rio_writen, Rio_readinitb, 
//                   Rio_readlineb, addCacheLine, Close, various C functions
//
// Helpful code: Nothing complete fits, but you could look at
//               serve_static and read_requesthdrs in tiny.c
void makeRequest(int connfd, char * uri, char * request, 
                 char * host, char * port)
{
   return;
}

// getPort
// Retrieves the port from the uri if present.
// If not present, the port defaults to "80"
// Example:  http://localhost:12345/godzilla.jpg
//          port is 12345
void getPort(char * port, char * uri)
{
   return;
}

// getHost
// Retrieves the host from the uri.  This function is
// called if the request doesn't have a Host line.
// Example:  http://localhost:12345/godzilla.jpg
//           host is localhost
void getHost(char * host, char * uri)
{
   return;
}

// getPath
// Retrieves the path from the uri.
// Example:  http://localhost:12345/godzilla.jpg
//           path is /godzilla.jpg
void getPath(char * path, char * uri)
{
   return;
}

// parseURI
// Parses the uri to obtain the host, path, and port from
// the uri. host may have been already obtained from a
// Host: header liner.
//
// Helper functions: getHost, getPort, getPath, various C functions
void parseURI(char * uri, char * host, char * path, char * port)
{
   return;
}

// getRequest
// Reads the request from the client via the connected
// socket. Gets the method, uri, and version from the
// request line.  The headers are read and discarded except
// for the Host: header line.  In that case, the host
// buffer is initialized to the host from the Host:
// header line.  For example,
// Host: localhost:12345
// causes host to be set to "localhost"
//
// Helper functions: Rio_readinitb, Rio_readlineb,
//                   various C functions
// Helpful code: read_requesthdrs in tiny.c
void getRequest(int connfd, char * method, char * uri, 
                char * version, char * host)
{
   return;
}

// isValid
// This function returns 1 if the method is GET
// and the version is either HTTP/1.1 or HTTP/1.0.
// Otherwise this function returns 0.
int isValid(char * method, char * version)
{
   return 0;
}
   
