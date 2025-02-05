#include <string>
#include <cstdlib>
#include <unordered_set>
#include <ctime>
#define NO_FEMALE_NAMES 100
#define NO_MALE_NAMES 100
#define NO_LAST_NAMES 199
#define NO_LAST_PREFIXES 3

/* A drop-in class for generating random names on the fly. Useful for testing code. */
class RandName {
    public:
        RandName();
        std::string GenName();
        void Clear();
    protected:
        std::unordered_set<std::string> used;
};

/* Implementation. */

std::string female_names[NO_FEMALE_NAMES] = {
    "Mary", "Patricia", "Linda", "Barbara", "Elizabeth", 
    "Jennifer", "Maria", "Susan", "Margaret", "Dorothy", 
    "Lisa", "Nancy", "Karen", "Betty", "Helen", 
    "Sandra", "Donna", "Carol", "Ruth", "Sharon", 
    "Michelle", "Laura", "Sarah", "Kimberly", "Deborah", 
    "Jessica", "Shirley", "Cynthia", "Angela", "Melissa", 
    "Brenda", "Amy", "Anna", "Rebecca", "Virginia", 
    "Kathleen", "Pamela", "Martha", "Debra", "Amanda", 
    "Stephanie", "Carolyn", "Christine", "Marie", "Janet", 
    "Catherine", "Frances", "Ann", "Joyce", "Diane", 
    "Alice", "Julie", "Heather", "Teresa", "Doris", 
    "Gloria", "Evelyn", "Jean", "Cheryl", "Mildred", 
    "Katherine", "Joan", "Ashley", "Judith", "Rose", 
    "Janice", "Kelly", "Nicole", "Judy", "Christina", 
    "Kathy", "Theresa", "Beverly", "Denise", "Tammy", 
    "Irene", "Jane", "Lori", "Rachel", "Marilyn", 
    "Andrea", "Kathryn", "Louise", "Sara", "Anne", 
    "Jacqueline", "Wanda", "Bonnie", "Julia", "Ruby", 
    "Lois", "Tina", "Phyllis", "Norma", "Paula", 
    "Diana", "Annie", "Lillian", "Emily", "Robin"
};

std::string male_names[NO_MALE_NAMES] = {
    "James", "John", "Robert", "Michael", "William", 
    "David", "Richard", "Charles", "Joseph", "Thomas", 
    "Christopher", "Daniel", "Paul", "Mark", "Donald", 
    "George", "Kenneth", "Steven", "Edward", "Brian", 
    "Ronald", "Anthony", "Kevin", "Jason", "Matthew", 
    "Gary", "Timothy", "Jose", "Larry", "Jeffrey", 
    "Frank", "Scott", "Eric", "Stephen", "Andrew", 
    "Raymond", "Gregory", "Joshua", "Jerry", "Dennis", 
    "Walter", "Patrick", "Peter", "Harold", "Douglas", 
    "Henry", "Carl", "Arthur", "Ryan", "Roger", 
    "Joe", "Juan", "Jack", "Albert", "Jonathan", 
    "Justin", "Terry", "Gerald", "Keith", "Samuel", 
    "Willie", "Ralph", "Lawrence", "Nicholas", "Roy", 
    "Benjamin", "Bruce", "Brandon", "Adam", "Harry", 
    "Fred", "Wayne", "Billy", "Steve", "Louis", 
    "Jeremy", "Aaron", "Randy", "Howard", "Eugene", 
    "Carlos", "Russell", "Bobby", "Victor", "Martin", 
    "Ernest", "Phillip", "Todd", "Jesse", "Craig", 
    "Alan", "Shawn", "Clarence", "Sean", "Philip", 
    "Chris", "Johnny", "Earl", "Jimmy", "Antonio"
};

std::string last_names[NO_LAST_NAMES] = {
    "Smith", "Johnson", "Williams", "Brown", "Jones", 
    "Miller", "Davis", "Garcia", "Rodriguez", "Wilson", 
    "Martinez", "Anderson", "Taylor", "Thomas", "Hernandez", 
    "Moore", "Martin", "Jackson", "Thompson", "White", 
    "Lopez", "Lee", "Gonzalez", "Harris", "Clark", 
    "Lewis", "Robinson", "Walker", "Perez", "Hall", 
    "Young", "Allen", "Sanchez", "Wright", "King", 
    "Scott", "Green", "Baker", "Adams", "Nelson", 
    "Hill", "Ramirez", "Campbell", "Mitchell", "Roberts", 
    "Carter", "Phillips", "Evans", "Turner", "Torres", 
    "Parker", "Collins", "Edwards", "Stewart", "Flores", 
    "Morris", "Nguyen", "Murphy", "Rivera", "Cook", 
    "Rogers", "Morgan", "Peterson", "Cooper", "Reed", 
    "Bailey", "Bell", "Gomez", "Kelly", "Howard", 
    "Ward", "Cox", "Diaz", "Richardson", "Wood", 
    "Watson", "Brooks", "Bennett", "Gray", "James", 
    "Reyes", "Cruz", "Hughes", "Price", "Myers", 
    "Long", "Foster", "Sanders", "Ross", "Morales", 
    "Powell", "Sullivan", "Russell", "Ortiz", "Jenkins", 
    "Gutierrez", "Perry", "Butler", "Barnes", "Fisher", 
    "Henderson", "Coleman", "Simmons", "Patterson", "Jordan", 
    "Reynolds", "Hamilton", "Graham", "Kim", "Gonzales", 
    "Alexander", "Ramos", "Wallace", "Griffin", "West", 
    "Cole", "Hayes", "Chavez", "Gibson", "Bryant", 
    "Ellis", "Stevens", "Murray", "Ford", "Marshall", 
    "Owens", "Harrison", "Ruiz", "Kennedy", "Wells", 
    "Alvarez", "Woods", "Mendoza", "Castillo", "Olson", 
    "Webb", "Washington", "Tucker", "Freeman", "Burns", 
    "Henry", "Vasquez", "Snyder", "Simpson", "Crawford", 
    "Jimenez", "Porter", "Mason", "Shaw", "Gordon", 
    "Wagner", "Hunter", "Romero", "Hicks", "Dixon", 
    "Hunt", "Palmer", "Robertson", "Black", "Holmes", 
    "Stone", "Meyer", "Boyd", "Mills", "Warren", 
    "Fox", "Rose", "Rice", "Moreno", "Schmidt", 
    "Patel", "Ferguson", "Nichols", "Herrera", "Medina", 
    "Ryan", "Fernandez", "Weaver", "Daniels", "Stephens", 
    "Gardner", "Payne", "Kelley", "Dunn", "Pierce", 
    "Arnold", "Tran", "Spencer", "Peters", "Hawkins", 
    "Grant", "Hansen", "Castro", "Hoffman", "Hart", 
    "Elliott", "Cunningham", "Knight", "Bradley"
};

std::string last_prefixes[NO_LAST_PREFIXES] = {
    "Mc", "Mac", "O'"
};

/* Initialize the RNG. */
RandName::RandName() {
    srand48(time(NULL));
}

/* Generate a name. */
std::string RandName::GenName() {
    std::string name;
    char gender;

    do {
        name = "";
        gender = (lrand48() % 2 == 0) ? 'm' : 'f';

        /* First name. */
        if (gender == 'm') {
            name += male_names[lrand48() % NO_MALE_NAMES];
        }
        else {
            name += female_names[lrand48() % NO_FEMALE_NAMES];
        }

        /* Middle name. */
        if (lrand48() % 5 == 0) {
            name += " ";
            if (gender == 'm') name += male_names[lrand48() % NO_MALE_NAMES];
            else name += female_names[lrand48() % NO_FEMALE_NAMES];
        } 

        /* Last name. */
        if (lrand48() % 99 != 0) {
            name += " ";

            if (lrand48() % 25 == 0) name += last_prefixes[lrand48() % NO_LAST_PREFIXES];
            name += last_names[lrand48() % NO_LAST_NAMES];
        }
    } while (used.find(name) != used.end());

    used.insert(name);
    return name;
}

/* Reset the stored names. */
void RandName::Clear() {
    used.clear();
}
