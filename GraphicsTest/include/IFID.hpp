#ifndef _IFID_H
#define _IFID_H

#include <string>

using namespace std;

/**
 * @brief Registrador intermediario IFID
 */
class IFID{
	private:
		string ir;
		int npc;
	public:
		IFID();
		void setIR(string ir);
		void setNPC(int npc);
		string getIR();
		int getNPC();
        void reset();

};

#endif
