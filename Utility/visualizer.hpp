#pragma once

struct Vis {
    double W;
    ofstream ofs;
    Vis(double L, double D, double width, double height, string s = "vis.html")
        : W(width) {
        L *= .01;
        D *= .01;
        width *= .01;
        height *= .01;
        ofs = ofstream(s.c_str());
        ofs << "<svg viewBox=\"";
        ofs << L << " " << D << " " << width << " " << height;
        ofs << " \" xmlns=\"http://www.w3.org/2000/svg\">\n";
    }
    void line(pair<double, double> p, pair<double, double> q,
              string col = "black") {
        string out = "<line x1=\"" + to_string(p.first * .01) + "\" y1=\"" +
                     to_string(p.second * .01) + "\" x2=\"" +
                     to_string(q.first * .01) + "\" y2=\"" +
                     to_string(q.second * .01) + "\" stroke=\"" + col +
                     "\" />\n";
        ofs << out;
    }
    void polygon(vector<pair<int, int>> poly, string col = "black") {
        string out = "<polygon points =\"";
        for (auto &[x, y] : poly)
            out += to_string(double(x) * .01) + "," +
                   to_string(double(y) * .01) + " ";
        out += "\" fill=\"" + col + "\" />\n";
        ofs << out;
    }
    void point(double x, double y, int id = -1, string col = "black") {
        x *= .01;
        y *= .01;
        double rad = W * .0001;
        string out = "<circle cx=\"" + to_string(x) + "\" cy=\"" + to_string(y);
        out += "\" r=\"" + to_string(rad) + "\" fill=\"" + col + "\" />\n";
        ofs << out;
        if (id != -1) {
            out = "<text x = \"" + to_string(x) + "\" y = \"" + to_string(y) +
                  "\" font-size =\"" + to_string(rad) +
                  "\" text-anchor = \"middle\" dy =\".3em\" fill=\"white\" "
                  ">" +
                  to_string(id) + "</text>\n";
            ofs << out;
        }
    }
    ~Vis() {
        ofs << "</svg>\n";
        ofs.close();
    }
};

/**
 * @brief Visualizer
 */