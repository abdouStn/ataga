#ifndef ENCODED_SEQUENCE_2B_H
#define ENCODED_SEQUENCE_2B_H

#include "encodedSequence.h"

class EncodedSequence2b : virtual public EncodedSequence
{
private:
	virtual void encodeSeq(const char* raw_seq);
	virtual void loadAFasta(std::string leFichier);
	virtual void loadAFastq(std::string leFichier);

public:
	EncodedSequence2b();
	EncodedSequence2b(const char* raw_seq);
	EncodedSequence2b(std::string leFichier, bool isAFasta);
	EncodedSequence2b(const EncodedSequence& es);  // constructeur par copie

	//virtual size_t length() const;
	//virtual void print();

	virtual void setSymbolAt(size_t i, char c);
	virtual EncodedSequence2b reverseComplement() const ;
	virtual char operator[](size_t i) const;   // remplace la methode getSymbolAt(size_t i). commence à 0 ou 1?
	virtual EncodedSequence &operator()(size_t start, size_t end=-1) const ;  //remplace la methode  getSubSequence() avec parametre par defaut
	virtual EncodedSequence& operator=(const EncodedSequence& es);  // operateur affectation.	
	virtual bool operator==(const EncodedSequence& es) const;  // operateur d'égalité.	

	virtual ~EncodedSequence2b();
};
/*
bool estValide(char nuc);
size_t donneOctect(size_t i);
size_t donnePositionOctect(size_t i);
unsigned char encode(char nuc) ;
char decode(unsigned char nuc);
*/
#endif