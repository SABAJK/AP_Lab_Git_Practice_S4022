#include "Score.h"

int Score::ID_generator = 0;

Score::Score(int score,const char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score::Score(int score,const string detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score::Score():ID(0)
{
	score = 0;
	label = GREAT;
	detail = " ";
}

void print(const Score& score)
{
	cout << "Score: " << score.score << endl;
    cout << "Label: ";
    switch (score.label)
    {
        case Score::GREAT:
            cout << "GREAT";
            break;
        case Score::GOOD:
            cout << "GOOD";
            break;
        case Score::NOTBAD:
            cout << "NOTBAD";
            break;
        case Score::BAD:
            cout << "BAD";
            break;
    }
    cout << endl;
    cout << "Detail: " << score.detail << endl;
}
void Score::set_score(int _score){score = _score;}
void Score::set_label(Label _label){label = _label;}
void Score::set_detail(const string& _detail){detail = _detail;}
void Score::setID_generator(int id_g){ID_generator = id_g;}
Score Score::operator=(const Score &sc)
{
    Score res(sc.score,sc.detail,sc.label);
    return res;
}
Score::~Score(){}  
