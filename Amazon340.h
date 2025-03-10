#ifndef AMAZON_340_H
#define AMAZON_340_H

#include <string>
#include "Vendor.h"

class Amazon340
{
	private:
		Vendor vendor;

	public:
		Amazon340();
		virtual ~Amazon340();

		void createVendor(const std::string& username, const std::string& email, const std::string& password, 
			const std::string& bio, const std::string& profilePicture);

		Vendor getVendor() const;
};

#endif
