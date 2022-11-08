#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

#ifndef _BOOL // Defining the data type bool where if try
typedef unsigned int bool;
static const bool false = 0;
static const bool true = 1;
#endif

#define NUMBER 5

// Setting up the environmnet for the only time when the user logins.
struct userBasic
{
    char name[20];
    int age;
    int cellphone; // Contact number of the user
};

struct userMedical
{
    int height;
    int weight;
    int dob;       // Stored in the format of ddmmyyy all in digits
    char hospital; // Hospital client is linked to -> which becomes the destination node
    int emergency; // Emergency contact number to ring in case of emergency
};

// Implementing the routing protocol

// Details about each and every node (hospital) in the network
struct node
{
    char nodeName;
    int nodeId;
    bool visited;
};

// Queue used for traversing the network
int queue[10];
int rear = (-1);
int front = (0);
int queueItemCount = 0;

// Queue operations
void insert(int data)
{
    queue[++rear] == data;
    queueItemCount++;
}

int remove()
{
    queueItemCount--;
    int c = queue[front++];
    return c;
}

bool isQueueEmpty()
{
    return queueItemCount == 0;
}

// graph functions

// graph specifications
char nodeName[5] = {'S', 'A', 'B', 'C', 'D'}; // An array of names of all the nodes(hospitals) in the network
int nodeId[5] = {1, 2322, 2534, 34534, 3323}; // Id's of all the nodes in the network
int graphConnection[10][10] = {{0, 1, 0, 1, 0},
                               {1, 0, 1, 1, 0},
                               {0, 1, 0, 0, 1},
                               {1, 1, 0, 0, 1},
                               {0, 0, 1, 1, 0}}; // An array depecting the connections between the nodes(hospitals) -> Adjanceny matrix

// struct Vertex vertexList[NUMBER];  An array of structures having the info about each node

// To get the adjacent nodes of a particular node in the network
int getAdjUnvisitedVertex(int vertexIndex)
{
    int i;
    for (i = 0; i < NUMBER; i++)
    {
        if (graphConnection[vertexIndex][i] == 1 && vertexList[i].visited == false)
            return i;
    }
    return -1;
}

// The rreq packet contents
struct rreq
{
    char ans[5];
    int sourceId;
    int destinationId;
};
struct rreq packet;

int main()
{
    printf("\n");
    printf("Welcome!\nBefore moving further pls enter your essential details - \n");
    struct userBasic user1Basic;
    struct userMedical user1Medical;

    // Entering the basic details of the user in the structure
    printf("User's name - ");
    scanf("%s", &user1Basic.name);
    printf("User's age - ");
    scanf("%d", &user1Basic.age);
    printf("Your contact number - ");
    scanf("%d", &user1Basic.cellphone);

    // Entering the medical details of the user in the structure
    printf("User's heigth(in cms) and weight(in kg) - ");
    scanf("%d %d", &user1Medical.height, &user1Medical.weight);
    printf("User's date of birth(dd/mm/yy) - ");
    scanf("%d", &user1Medical.dob);
    printf("User's emergency contact number - ");
    scanf("%d", &user1Medical.emergency);
    printf("User's registered hospital - ");
    scanf("%d", &user1Medical.hospital); // A single character representing the hospital present in the network
    printf("Thankyou for the details.\nInstallation complete");
    printf("\n");

    struct Vertex *vertexList[NUMBER];

    for (int i = 0; i < NUMBER; i++)
    {
        &vertexList[i]->label = nodeName[i];
        &vertexList[i]->nodeId = nodeId[i];
        &vertexList[i]->visited = false;
    }

    int j = 0; // For traversing the answer array in the rreq structure
    packet.sourceId = nodeId[0];
    for (int i = 0; i < NUMBER; i++)
    {
        if (user1Medical.hospital == nodeName[i])
        {
            packet.destinationId = nodeId[i];
        }
    }

    printf("%d - Destination Id \n%d - Source Id\n", packet.destinationId, packet.sourceId);

    vertexList[0].visited = true;
    insert(0);

    return 0;
}
