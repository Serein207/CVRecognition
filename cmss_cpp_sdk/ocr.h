#ifndef __CMSS_AI_OCR_H__
#define __CMSS_AI_OCR_H__

#include "base/base.h"

namespace cmssai {

    class Ocr: public AipBase
    {
    public:			
		std::string _form = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/form";
		std::string _generic = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/generic";
		
		std::string _taxi = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/taxiinvoice";
		std::string _toll = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/toll";
		std::string _trainticket = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/trainticket";
		std::string _invoice = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/invoice";
		std::string _fixedinvoice = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/fixedinvoice";
		std::string _flight = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/flights";
		std::string _mixedbills = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/mixedbills";
		
		std::string _general = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/general";
		std::string _handwriting = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/handwriting";
		std::string _webimage = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/webimage";
		
		std::string _seal = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/seal";
		std::string _sealrecognition = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/sealrecognition";
		
		std::string _bankcard = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/bankcard";
		std::string _businesscard = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/businesscard";
		std::string _businesslicense = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/businesslicense";
		std::string _enterpriselicense = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/enterpriselicense";
		std::string _idcard = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/idcard";
		
		std::string _ammeter = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/ammeter";
		std::string _driving = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/driving";
		std::string _drive = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/drive";
		std::string _vincode = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/vincode";
		std::string _licenseplate = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/licenseplate";
		
		std::string _formula = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/formula";
		
		std::string _custom = "https://api-wuxi-1.cmecloud.cn:8443/api/ocr/v1/selfdefinition";

        Ocr(const std::string & ak, const std::string & sk): AipBase(ak, sk)
        {
        }
		
		std::string form_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_form, null, data, null);
            return result;
        }

		std::string generic_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_generic, null, data, null);
            return result;
        }
		
		std::string taxi_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_taxi, null, data, null);
            return result;
        }
		
		std::string toll_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_toll, null, data, null);
            return result;
        }
		
		std::string trainticket_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_trainticket, null, data, null);
            return result;
        }
		
		std::string invoice_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_invoice, null, data, null);
            return result;
        }
		
		std::string fixedinvoice_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_fixedinvoice, null, data, null);
            return result;
        }

		std::string flight_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_flight, null, data, null);
            return result;
        }
		
		std::string mixedbills_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_mixedbills, null, data, null);
            return result;
        }
		
		std::string general_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_general, null, data, null);
            return result;
        }

		std::string handwriting_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_handwriting, null, data, null);
            return result;
        }
		
		std::string webimage_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_webimage, null, data, null);
            return result;
        }

		std::string seal_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_seal, null, data, null);
            return result;
        }
		
		std::string sealrecognition_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_sealrecognition, null, data, null);
            return result;
        }

		std::string bankcard_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_bankcard, null, data, null);
            return result;
        }
		
		std::string businesscard_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_businesscard, null, data, null);
            return result;
        }

		std::string businesslicense_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_businesslicense, null, data, null);
            return result;
        }

		std::string enterpriselicense_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_enterpriselicense, null, data, null);
            return result;
        }

		std::string idcard_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_idcard, null, data, null);
            return result;
        }
        
		std::string ammeter_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_ammeter, null, data, null);
            return result;
        }

		std::string drive_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_drive, null, data, null);
            return result;
        }

		std::string driving_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_driving, null, data, null);
            return result;
        }
		
		std::string vincode_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_vincode, null, data, null);
            return result;
        }
		
		std::string licenseplate_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_licenseplate, null, data, null);
            return result;
        }
		
		std::string formula_url(
            std::string const & url,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["url"] = url;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_formula, null, data, null);
            return result;
        }

		std::string custom_url(
            std::string const & url,
			std::string const & templateid,
            const std::map<std::string, std::string> & options)
        {
            std::map<std::string, std::string> data;
            data["Url"] = url;
			data["TemplateId"] = templateid;
            std::copy(options.begin(), options.end(), std::inserter(data, data.end()));
            std::string result =
                this->request(_custom, null, data, null);
            return result;
        }
        
    };
}
#endif
