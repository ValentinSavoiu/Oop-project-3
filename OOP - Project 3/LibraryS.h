#pragma once

class LibraryS {  // SINGLETON
	vector <Info*> lib;
	static LibraryS *s_lib;
	LibraryS() {};
	LibraryS(const LibraryS &a) {}
	LibraryS& operator = (const LibraryS &lib) {}
public:
	~LibraryS() {};
	static LibraryS * get_instance() {
		if (s_lib == 0)
			s_lib = new LibraryS;
		return s_lib;
	}


	vector <Info*> :: iterator find_by_name(string name = "") {
		if (name == "") {
			string s_name;
			cout << "\nIntroduceti numele informatiei: ";
			cin >> s_name;
			name = s_name;
		}
		for (auto x = lib.begin(); x != lib.end(); ++x) 
			if (name == (*x)->name)  return x;
		return lib.end();
	}
	vector <Info*> :: iterator find_by_id() {
		int ID;
		cout << "\nIntroduceti id-ul informatiei: ";
		cin >> ID;
		for (auto x = lib.begin(); x != lib.end(); ++x) 
			if (ID == (*x)->id) return x;
		return lib.end();
	}
	template <class U> void retrieve_by_value(char type = 'b', U VAL = nullptr) {
		if (type == 'b') {
			char Type;
			cout << "\nIntroduceti tipul valorii cautate urmat de valoare: a - adresa, i - int, c - numar complex, s - string: ";
			cin >> Type;
			switch (Type) {
				case 's':
				{
					string val;
					cin >> val;
					return retrieve_by_value(Type, val);
					break;
				}
				case 'i':
				{
					int val;
					cin >> val;
					return retrieve_by_value(Type, val);
					break;
				}
				case 'c':
				{
					ComplexNumber val;
					cin >> val;
					return retrieve_by_value(Type, val);
					break;
				}
				case 'a':
				{
					Address val;
					cin >> val;
					return retrieve_by_value(Type, val);
					break;
				}
				default:
				{
					throw "caracter invalid";
				}
			}
		}
		else {
			bool OK = 0;
			for (auto x = lib.begin(); x != lib.end(); ++x) {
				if ((*x)->type() != type) continue;
				InfoVal<U> *inf = static_cast<InfoVal<U>*>(*x);
				if (inf->value == VAL) {
					cout << **x << '\n';
					OK = 1;
				}
			}
			if (OK == 0) cout << "\nNici-un element nu are aceasta valoare\n";
		}
			
	}

	void retrieve_by_name() {
		auto it = find_by_name();
		if (it == lib.end()) cout << "\nElementul nu exista\n";
		cout << **it << '\n';
	}

	void retrieve_by_id() {
		auto it = find_by_id();
		if (it == lib.end()) cout << "\nElementul nu exista\n";
		cout << **it << '\n';
	}


	friend ostream& operator << (ostream &out, LibraryS& l) {
		for (auto x : l.lib) {
			out << *x << '\n';
		}
		return out;
	}

	string delete_by_name() {
		auto it = find_by_name();
		if (it == lib.end()) return "\nElementul nu exista\n";
		delete *it;
		lib.erase(it);
		return "\nStergere realizata cu succes\n";
	}
	string delete_by_id() {
		auto it = find_by_id();
		if (it == lib.end()) return "\nElementul nu exista\n";
		delete *it;
		lib.erase(it);
		return "\nStergere realizata cu succes\n";
	}


	void add() {
		cout << "\nIntroduceti tipul informatiei, urmat de nume si valoare\n s = string \n i = int\n c = complex number\n a = address\n";
		char type;
		string name;
		cin >> type >> name;
		auto it = find_by_name(name);
		
		Info* inf;
		inf = NULL;
		switch (type) {
			case 's': {
				string val;
				cin >> val;
				inf = (Info*) new InfoVal<string>(name, val);
				break;
			}
			case 'i': {
				int val;
				cin >> val;

				inf = (Info*) new InfoVal<int>(name, val);
				break;
			}
			case 'c': {
				ComplexNumber val;
				cin >> val;
				inf = (Info*) new InfoVal<ComplexNumber>(name, val);
				break;
			}
			case 'a': 
			{
				Address val;
				cin >> val;
				inf = (Info*) new InfoVal<Address>(name, val);
				break;
			}
			default:
			{
				throw "caracter invalid";
			}
		}
		if (it != lib.end()) {
			cout << "\nAtasat la o informatie anterioara\n";
			**it += inf;
			--Info::currID;
			return;
		}
		cout << "ID-ul asociat este: " << inf->id << '\n';
		lib.push_back(inf);
	}
	void clear() {
		for (auto x = lib.begin(); x != lib.end(); ++x)
			delete *x;
		lib.clear();
	}
	void interact() {
		cout << "\n MENIU\n 1 - adaugare informatie\n 2 - stergere informatie dupa nume\n 3 - stergere informatie dupa id\n 4 - cautare informatie dupa valoare\n 5 - cautare informatie dupa nume\n";
		cout << " 6 - cautare informatie dupa id\n-1 - incetare executie program\n";
		int command;
		cin >> command;
		switch (command) {
			case 1:
			{
				add();
				break;
			}
			case 2: 
			{
				cout << delete_by_name();
				break;
			}
			case 3: 
			{
				cout << delete_by_id();
				break;
			}
			case 4: 
			{
				retrieve_by_value('b', string("ac"));
				break;
			}
			case 5:
			{
				retrieve_by_name();
				break;
			}
			case 6:
			{
				retrieve_by_id();
				break;
			}
			default:
			{
				clear();
				cout << "\nInchidere cu succes\n";
				return;
			}
		}
		interact();
	}
};
LibraryS *LibraryS::s_lib = 0;


