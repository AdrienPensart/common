#pragma once

#include "RandomHat.hpp"

namespace Common {
	template<class T>
	class DoubleHat {
			Hat one;
			Hat two;
			Hat * current;

		public:
			DoubleHat() : current (&one) {
			}

			// retire un élément de la pile aléatoirement
			T pop() {
				if(!size()) {
					exchange();
				}
				T temp = other()->push_back(current->randomPop());
				return temp;
			}

			size_t size() {
				return current->size();
			}

		private:
			Hat * other() {
				return current == one ? &two : &one;
			}

			void exchange() {
				current = other();
			}
	};
} // Common
