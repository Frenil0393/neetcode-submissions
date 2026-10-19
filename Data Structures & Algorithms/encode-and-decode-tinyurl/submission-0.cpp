class Solution {
private:
    unordered_map<string, string> longToShort;
    unordered_map<string, string> shortToLong;
    int counter = 0;
    const string base = "http://tinyurl.com/";

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // If already encoded, return existing short URL
        if (longToShort.find(longUrl) != longToShort.end()) {
            return longToShort[longUrl];
        }
        // Generate new short URL
        string shortUrl = base + to_string(counter++);
        longToShort[longUrl] = shortUrl;
        shortToLong[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortToLong[shortUrl];
    }
};