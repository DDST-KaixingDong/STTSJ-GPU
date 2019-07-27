#include "util.h"


using namespace std;
// global function for Preprocess class; global wheels

extern int timeseeds;

void split(std::string s, std::string delim, std::vector<std::string>* ret)
{
	size_t last = 0;
	size_t index = s.find_first_of(delim, last); // find is ok 2
	while (index != std::string::npos) // not not success   std::string::npos is -1 actually
	{
		std::string stmp = s.substr(last, index - last);
		if (stmp.length() != 0) ret->push_back(stmp); // std::vector������push_back NULL�ַ�
		last = index + delim.size();
		index = s.find_first_of(delim, last);
		//cout << index << endl;
	}
	if (last < s.size()) // ��β��delim
	{
		std::string stmp = s.substr(last, index - last);
		if (stmp.length() != 0) ret->push_back(stmp);
	}
	//if (index - last > 0) // wrong judgement!!  ��β��delim index == std::string::npos
	//{
	//	ret->push_back(s.substr(last, index - last));
	//}
}


void split2(std::string s, std::string delim, std::vector<std::string>* ret)
{
	size_t last = 0;
	size_t index = s.find(delim, last); // find is ok 2
	while (index != std::string::npos) // not not success   std::string::npos is a big num
	{
		ret->push_back(s.substr(last, index - last));
		last = index + delim.length();
		index = s.find(delim, last);
		//cout << index << endl;
	}
	if (s.size() - last > 0) // index == std::string::npos ��β��delim
	{
		ret->push_back(s.substr(last, s.size() - last));
	}
}

void split3(std::string s, std::string delim, std::vector<std::string>* ret)
{
	size_t last = 0;
	size_t index = s.find_first_of(delim, last); // find is ok 2
	while (index != std::string::npos) // not not success   std::string::npos is a big num
	{
		std::string stmp = s.substr(last, index - last);
		if (stmp.length() != 0) {
			ret->push_back(stmp); // std::vector������push_back NULL�ַ�
			cout << stmp.length() << endl << stmp << endl;
		}
		last = index + delim.size();
		index = s.find_first_of(delim, last);
		//cout << index << endl;
	}
	if (last < s.size()) // ��β��delim
	{
		cout << "step2" << endl;
		std::string stmp = s.substr(last, index - last);
		if (stmp.length() != 0) {
			ret->push_back(stmp);
			cout << stmp.length() << endl << stmp << endl;
		}
	}
	//if (index - last > 0) // wrong judgement!!  ��β��delim index == std::string::npos
	//{
	//	ret->push_back(s.substr(last, index - last));
	//}
}


// inline �������� ��θ�
float calculateDistance(float LatA, float LonA, float LatB, float LonB)
{
	float Pi = 3.1415926;
	float R = 6371004; // ��λ����
	float MLatA, MLatB, MLonA, MLonB;
	MLatA = 90 - LatA;
	MLatB = 90 - LatB;
	MLonA = LonA;
	MLonB = LonB;
	float C = sin(MLatA)*sin(MLatB)*cos(MLonA - MLonB) + cos(MLatA)*cos(MLatB);
	float Distance = R*acos(C)*Pi / 180;
	return Distance;
}



void GetTF(std::vector<std::string>* keywords, std::vector<std::string>* corpus) {
	//set<std::string> stopwords = { " ","able","about","above","according","accordingly","across","actually","after","afterwards","again","against","ain't","all","allow","allows","almost","alone","along","already","also","although","always","am","among","amongst","an","and","another","any","anybody","anyhow","anyone","anything","anyway","anyways","anywhere","apart","appear","appreciate","appropriate","are","aren't","around","as","a's","aside","ask","asking","associated","at","available","away","awfully","be","became","because","become","becomes","becoming","been","before","beforehand","behind","being","believe","below","beside","besides","best","better","between","beyond","both","brief","but","by","came","can","cannot","cant","can't","cause","causes","certain","certainly","changes","clearly","c'mon","co","com","come","comes","concerning","consequently","consider","considering","contain","containing","contains","corresponding","could","couldn't","course","c's","currently","definitely","described","despite","did","didn't","different","do","does","doesn't","doing","done","don't","down","downwards","during","each","edu","eg","eight","either","else","elsewhere","enough","entirely","especially","et","etc","even","ever","every","everybody","everyone","everything","everywhere","ex","exactly","example","except","far","few","fifth","first","five","followed","following","follows","for","former","formerly","forth","four","from","further","furthermore","get","gets","getting","given","gives","go","goes","going","gone","got","gotten","greetings","had","hadn't","happens","hardly","has","hasn't","have","haven't","having","he","hello","help","hence","her","here","hereafter","hereby","herein","here's","hereupon","hers","herself","he's","hi","him","himself","his","hither","hopefully","how","howbeit","however","i'd","ie","if","ignored","i'll","i'm","immediate","in","inasmuch","inc","indeed","indicate","indicated","indicates","inner","insofar","instead","into","inward","is","isn't","it","it'd","it'll","its","it's","itself","i've","just","keep","keeps","kept","know","known","knows","last","lately","later","latter","latterly","least","less","lest","let","let's","like","liked","likely","little","look","looking","looks","ltd","mainly","many","may","maybe","me","mean","meanwhile","merely","might","more","moreover","most","mostly","much","must","my","myself","name","namely","nd","near","nearly","necessary","need","needs","neither","never","nevertheless","new","next","nine","no","nobody","non","none","noone","nor","normally","not","nothing","novel","now","nowhere","obviously","of","off","often","oh","ok","okay","old","on","once","one","ones","only","onto","or","other","others","otherwise","ought","our","ours","ourselves","out","outside","over","overall","own","particular","particularly","per","perhaps","placed","please","plus","possible","presumably","probably","provides","que","quite","qv","rather","rd","re","really","reasonably","regarding","regardless","regards","relatively","respectively","right","said","same","saw","say","saying","says","second","secondly","see","seeing","seem","seemed","seeming","seems","seen","self","selves","sensible","sent","serious","seriously","seven","several","shall","she","should","shouldn't","since","six","so","some","somebody","somehow","someone","something","sometime","sometimes","somewhat","somewhere","soon","sorry","specified","specify","specifying","still","sub","such","sup","sure","take","taken","tell","tends","th","than","thank","thanks","thanx","that","thats","that's","the","their","theirs","them","themselves","then","thence","there","thereafter","thereby","therefore","therein","theres","there's","thereupon","these","they","they'd","they'll","they're","they've","think","third","this","thorough","thoroughly","those","though","three","through","throughout","thru","thus","to","together","too","took","toward","towards","tried","tries","truly","try","trying","t's","twice","two","un","under","unfortunately","unless","unlikely","until","unto","up","upon","us","use","used","useful","uses","using","usually","value","various","very","via","viz","vs","want","wants","was","wasn't","way","we","we'd","welcome","well","we'll","went","were","we're","weren't","we've","what","whatever","what's","when","whence","whenever","where","whereafter","whereas","whereby","wherein","where's","whereupon","wherever","whether","which","while","whither","who","whoever","whole","whom","who's","whose","why","will","willing","wish","with","within","without","wonder","won't","would","wouldn't","yes","yet","you","you'd","you'll","your","you're","yours","yourself","yourselves","you've","zero","zt","ZT","zz","ZZ"};
	//cout << stopwords.size();

	/************ utilizing python for TF-IDF as well as InvertedIndex, no need for repeated wheel-creating ***********/

}


void GetSample(std::vector<size_t> &taskSet1, std::vector<size_t> &taskSet2, int sizeP, int sizeQ) {
	
	// make status!
	int num = 5;
	int* along = new int[num]();
	along[0] = 0;
	along[1] = 9;
	along[2] = 50;
	along[3] = 69;
	along[4] = 107;

	for (size_t i = 0; i < sizeP; i++) {
		//taskSet1.push_back(a[rand() % num]);
		taskSet1.push_back(i);
	}
	//set<size_t> Q;

	for (size_t j = 0; j < sizeQ; j++) {
		//taskSet2.push_back(a[rand() % num]);
		taskSet2.push_back(j);
	}

	delete[] along;
}


void RandPerm(int MaxNum, int TestNum, vector<size_t> &id) {
	// O(n):
	// MaxNum >= TestNum
	vector<int> tmp;
	for (int i = 0; i < MaxNum; ++i) {
		tmp.push_back(i);
	}
	random_shuffle(tmp.begin(), tmp.end());

	for (int i = 0; i < TestNum; ++i) {
		id.push_back(tmp.at(i));
	}
}
 
void GetSample2(std::vector<STTrajectory> &dataptr, std::vector<size_t> &taskSet1, std::vector<size_t> &taskSet2, int sizeP, int sizeQ) {

	// make status!
	int num = 5;
	int* along = new int[num]();
	along[0] = 0;
	along[1] = 9;
	along[2] = 50;
	along[3] = 69;
	along[4] = 107;


	// way1:
	for (size_t i = 0; i < sizeP; i++) {
		//taskSet1.push_back(a[rand() % num]);
		taskSet1.push_back(i);
	}
	//set<size_t> Q;

	for (size_t j = 0; j < sizeQ; j++) {
		//taskSet2.push_back(a[rand() % num]);
		taskSet2.push_back(j);
	}



	for (int i = 0; i < taskSet1.size() - 1; ++i) {
		for (int j = i + 1; j < taskSet1.size(); ++j) {
			if (dataptr.at(taskSet1.at(i)).traj_length > dataptr.at(taskSet1.at(j)).traj_length) {
				std::swap(taskSet1.at(i), taskSet1.at(j));
			}
		}
	}
	// output:
	cout << "P trajlen dist.:\n";
	for (int i = 0; i < taskSet1.size(); i++)
		cout << dataptr.at(taskSet1.at(i)).traj_length << ' ';
	cout << endl;


	for (int i = 0; i < taskSet2.size() - 1; ++i) {
		for (int j = i + 1; j < taskSet2.size(); ++j) {
			if (dataptr.at(taskSet2.at(i)).traj_length > dataptr.at(taskSet2.at(j)).traj_length) {
				std::swap(taskSet2.at(i), taskSet2.at(j));
			}
		}
	}
	// output:
	cout << "Q trajlen dist.:\n";
	for (int i = 0; i < taskSet2.size(); i++)
		cout << dataptr.at(taskSet2.at(i)).traj_length << ' ';
	cout << endl;


	delete[] along;
}

void GetSample_Sorting(std::vector<STTrajectory> &dataptr, std::vector<size_t> &taskSet1, std::vector<size_t> &taskSet2, int sizeP, int sizeQ) {

	//// make status!

	//int num = 5;
	//int* along = new int[num]();
	//along[0] = 0;
	//along[1] = 9;
	//along[2] = 50;
	//along[3] = 69;
	//along[4] = 107;

	//for (size_t i = 0; i < sizeP; i++) {
	//	//taskSet1.push_back(a[rand() % num]);
	//	taskSet1.push_back(i);
	//}
	////set<size_t> Q;

	//for (size_t j = 0; j < sizeQ; j++) {
	//	//taskSet2.push_back(a[rand() % num]);
	//	taskSet2.push_back(j);
	//}

	//delete[] along;


	// way2:
	RandPerm(sizeP * 3 > MAXTRAJSIZE ? MAXTRAJSIZE : sizeP * 3 , sizeP, taskSet1);
	RandPerm(sizeQ * 3 > MAXTRAJSIZE ? MAXTRAJSIZE : sizeQ * 3 , sizeQ, taskSet2);



	for (int i = 0; i < taskSet1.size()-1; ++i) {
		for (int j = i + 1; j < taskSet1.size(); ++j) {
			if (dataptr.at(taskSet1.at(i)).traj_length > dataptr.at(taskSet1.at(j)).traj_length) {
				std::swap(taskSet1.at(i), taskSet1.at(j));
			}
		}
	}
	// output:
	cout << "P trajlen dist.:\n";
	for (int i = 0; i < taskSet1.size(); i++)
		cout << dataptr.at(taskSet1.at(i)).traj_length << ' ';
	cout << endl;
	

	for (int i = 0; i < taskSet2.size() - 1; ++i) {
		for (int j = i + 1; j < taskSet2.size(); ++j) {
			if (dataptr.at(taskSet2.at(i)).traj_length > dataptr.at(taskSet2.at(j)).traj_length) {
				std::swap(taskSet2.at(i), taskSet2.at(j));
			}
		}
	}
	// output:
	cout << "Q trajlen dist.:\n";
	for (int i = 0; i < taskSet2.size(); i++)
		cout << dataptr.at(taskSet2.at(i)).traj_length << ' ';
	cout << endl;

}


void GetSample_Filtering_Sorting(std::vector<STTrajectory> &dataptr, std::vector<size_t> &taskSet1, std::vector<size_t> &taskSet2, int sizeP, int sizeQ) {

	//// make status!

	//int num = 5;
	//int* along = new int[num]();
	//along[0] = 0;
	//along[1] = 9;
	//along[2] = 50;
	//along[3] = 69;
	//along[4] = 107;

	//for (size_t i = 0; i < sizeP; i++) {
	//	//taskSet1.push_back(a[rand() % num]);
	//	taskSet1.push_back(i);
	//}
	////set<size_t> Q;

	//for (size_t j = 0; j < sizeQ; j++) {
	//	//taskSet2.push_back(a[rand() % num]);
	//	taskSet2.push_back(j);
	//}

	//delete[] along;


	// way3:
	int MinLength = 2,MaxLength = 24;
	vector<int> tmp;
	for (int i = 0; i < dataptr.size(); i++) {
		if (dataptr.at(i).traj_length >= MinLength && dataptr.at(i).traj_length <= MaxLength)
			tmp.push_back(i);
	}
	//srand(1);
	//srand(time(0));
	//random_shuffle(tmp.begin(), tmp.end());
	cout << "len [" << MinLength << ',' << MaxLength << "] = " << tmp.size() << endl;

	//srand(1);
	//srand(time(0));
	srand(timeseeds); 
	for (int i = 0; i < sizeP; ++i) {
		taskSet1.push_back(tmp.at(rand() % tmp.size()));
	}

	//srand(1);
	//srand(time(0));
	srand(timeseeds);
	for (int i = 0; i < sizeQ; ++i) {
		taskSet2.push_back(tmp.at(rand() % tmp.size()));
	}
	//RandPerm(sizeP * 3 > MAXTRAJSIZE ? MAXTRAJSIZE : sizeP * 3, sizeP, taskSet1);
	//RandPerm(sizeQ * 3 > MAXTRAJSIZE ? MAXTRAJSIZE : sizeQ * 3, sizeQ, taskSet2);


	for (int i = 0; i < taskSet1.size() - 1; ++i) {
		for (int j = i + 1; j < taskSet1.size(); ++j) {
			if (dataptr.at(taskSet1.at(i)).traj_length > dataptr.at(taskSet1.at(j)).traj_length) {
				std::swap(taskSet1.at(i), taskSet1.at(j));
			}
		}
	}
	

	// output:
	//cout << "P trajlen dist.:\n";
	//for (int i = 0; i < taskSet1.size(); i++)
	//	cout << dataptr.at(taskSet1.at(i)).traj_length << ' ';
	//cout << endl;


	for (int i = 0; i < taskSet2.size() - 1; ++i) {
		for (int j = i + 1; j < taskSet2.size(); ++j) {
			if (dataptr.at(taskSet2.at(i)).traj_length > dataptr.at(taskSet2.at(j)).traj_length) {
				std::swap(taskSet2.at(i), taskSet2.at(j));
			}
		}
	}
	

	// output:
	//cout << "Q trajlen dist.:\n";
	//for (int i = 0; i < taskSet2.size(); i++)
	//	cout << dataptr.at(taskSet2.at(i)).traj_length << ' ';
	//cout << endl;

}



void GetSample_Filtering_NoSorting(std::vector<STTrajectory> &dataptr, std::vector<size_t> &taskSet1, std::vector<size_t> &taskSet2, int sizeP, int sizeQ) {

	//// make status!

	//int num = 5;
	//int* along = new int[num]();
	//along[0] = 0;
	//along[1] = 9;
	//along[2] = 50;
	//along[3] = 69;
	//along[4] = 107;

	//for (size_t i = 0; i < sizeP; i++) {
	//	//taskSet1.push_back(a[rand() % num]);
	//	taskSet1.push_back(i);
	//}
	////set<size_t> Q;

	//for (size_t j = 0; j < sizeQ; j++) {
	//	//taskSet2.push_back(a[rand() % num]);
	//	taskSet2.push_back(j);
	//}

	//delete[] along;


	// way3:
	int MinLength = 2, MaxLength = 24;
	vector<int> tmp;
	for (int i = 0; i < dataptr.size(); i++) {
		if (dataptr.at(i).traj_length >= MinLength && dataptr.at(i).traj_length <= MaxLength)
			tmp.push_back(i);
	}
	//random_shuffle(tmp.begin(), tmp.end());
	cout << "len [" << MinLength << ',' << MaxLength << "] = " << tmp.size() << endl;

	srand(timeseeds);
	for (int i = 0; i < sizeP; ++i) {
		taskSet1.push_back(tmp.at(rand() % tmp.size()));
	}
	srand(timeseeds);
	for (int i = 0; i < sizeQ; ++i) {
		taskSet2.push_back(tmp.at(rand() % tmp.size()));
	}
	//RandPerm(sizeP * 3 > MAXTRAJSIZE ? MAXTRAJSIZE : sizeP * 3, sizeP, taskSet1);
	//RandPerm(sizeQ * 3 > MAXTRAJSIZE ? MAXTRAJSIZE : sizeQ * 3, sizeQ, taskSet2);


	//for (int i = 0; i < taskSet1.size() - 1; ++i) {
	//	for (int j = i + 1; j < taskSet1.size(); ++j) {
	//		if (dataptr.at(taskSet1.at(i)).traj_length > dataptr.at(taskSet1.at(j)).traj_length) {
	//			std::swap(taskSet1.at(i), taskSet1.at(j));
	//		}
	//	}
	//}


	// output:
	//cout << "P trajlen dist.:\n";
	//for (int i = 0; i < taskSet1.size(); i++)
	//	cout << dataptr.at(taskSet1.at(i)).traj_length << ' ';
	//cout << endl;


	//for (int i = 0; i < taskSet2.size() - 1; ++i) {
	//	for (int j = i + 1; j < taskSet2.size(); ++j) {
	//		if (dataptr.at(taskSet2.at(i)).traj_length > dataptr.at(taskSet2.at(j)).traj_length) {
	//			std::swap(taskSet2.at(i), taskSet2.at(j));
	//		}
	//	}
	//}


	// output:
	//cout << "Q trajlen dist.:\n";
	//for (int i = 0; i < taskSet2.size(); i++)
	//	cout << dataptr.at(taskSet2.at(i)).traj_length << ' ';
	//cout << endl;

}