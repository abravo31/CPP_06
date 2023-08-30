# include "Base.hpp"

Base*   generate(void){
    int random = std::rand() % 3;
    switch (random){
        case 0:
            return new A();
            break;
        case 1:
            return new B();
            break;
        case 2:
            return new C();
            break;
        default:
            perror("Something went wrong with the random generator");
		return (NULL);
    }		
}

void    identify(Base* p){

    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
		std::cout << "Not Recognized\n";
}

void    identify_recursive( Base& p, int i ){
    
    try{
        switch (i)
        {
            case 0:
                dynamic_cast<A&>(p);
			    std::cout << "A" << std::endl;
                break;
            case 1:
                dynamic_cast<B&>(p);
			    std::cout << "B" << std::endl;
                break;
            case 2:
                dynamic_cast<C&>(p);
			    std::cout << "C" << std::endl;
                break;
        default:
            std::cout << "Not Recognized\n";
        }
    } catch (const std::exception& e){
        identify_recursive(p, i + 1);
    }
}

void    identify(Base& p){
    identify_recursive(p, 0);
}

int main (){
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Base *obj1 = generate();
    // Base obj2 = generate();
    // Base obj3 = generate();

    identify(obj1);
    identify(*obj1);
    // identify(obj3);

    delete obj1;
    // delete obj2;
    // delete obj3;

    return 0;
}