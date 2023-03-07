#pragma once

#include "../Include/Webserv.hpp"

class Request
{
	char 				*_begin;
	char 				*_end;
	char				*_remainder;
	char				*_begin_save;
	char				*_ptr;
	int					_remainder_size;
    Method				_method;
    std::string			_request_target;
	std::string			_http_version;
	std::string			_query;
	t_request_headers	_headers;
	std::ofstream		_body_;
	std::string 		_body_filename;
	size_t				_body_size;
	State				_request_state;
	bool				_keep_alive;
	
	void					startParsing();
	void					parseRequestLine();
	Method					extractMethod();
	std::string				extractRequestTarget();
	std::string				extractHttpVersion();
	std::string				extractQuery();
	void 					parseHeaderFields();
	std::string 			extractFieldName();
	std::list<std::string>	extractFieldValue(const std::string &field_name);
	std::list<std::string>	extractHeaderValue();
	std::list<std::string>	extractHostValue();
	std::list<std::string>	extractContentLengthValue();
	std::list<std::string> 	extractTransferEncodingValue();
	std::list<std::string>	extractTrailerValue();
	std::list<std::string>	extractConnectionValue();
	std::string				extractPort();
	std::string				extractTransferCoding();
	std::string				extractTransferParameter();
	std::string				extractToken();
	std::string				extractSegment();
	std::string				extractRegName();
	std::string				extractQuotedString();
	std::string				extractQuotedPair();
	std::string				extractFieldContent();
	void					readRequestBody();
	void					parseChunkedBody();	
	int						chunkHeader();
	int						extractChunkSize();
	std::string				extractChunkExtension();
	int						readChunkData(int chunk_size);
	void					parseTrailerPart();
	void					stateTransition();
	void 					shiftFromParseHeaderFields();
	void 					shiftFromParseChunkedBody();
	void					omitCharset(std::string char_set);
	void					skipStr(std::string str);
	bool					isalpha(char c);
	bool					isdigit(char c);
	bool					ishexdigit(char c);
	bool					istchar(char c);
	bool					isunreserved(char c);
	bool					isSubDelims(char c);
	bool					isPctEncoded();
	bool					isqdtext(unsigned char c);
	bool					isVchar(char c);
	bool					isObsText(unsigned char c);
	bool					isForbiddenTrailerValue(std::string field_name);
	std::string				urlEncoding(std::string url);

	public:
		Request();
		~Request();
		Method						getMethod();
		std::string					getUri();
		std::string					getQuery();
		const t_request_headers&	getHeaders();
		std::string 				getBodyFileName();
		int 						getBodySize();
		bool						isKeepAlive();
		Result						parse(const char *buff, int buff_size);
		void						reset();
};
