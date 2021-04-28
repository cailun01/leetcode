string getHostname(string &url) {
    int len = url.length();
    int i = 7;
    for(; i < len; i++) {
        if(url[i] == '/') {
            break;
        }
    }
    return url.substr(7, i - 7);
}

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unordered_set<string> res;
        unordered_set<string> visited;

        queue<string> bfs;
        // key is common url
        string key = getHostname(startUrl);
        res.insert(startUrl);
        bfs.push(startUrl);
        while(!bfs.empty()) {
            string url = bfs.front();
            bfs.pop();
            if(visited.find(url) != visited.end()) {
                continue;
            }
            visited.insert(url);
            vector<string> ans = htmlParser.getUrls(url);
            
            for(string s: ans) {
                if(getHostname(s) == key) {
                    bfs.push(s);
                    res.insert(s);
                }
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};

