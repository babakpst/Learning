
// babak poursartip
// Aug 28, 2022

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries)
    {

      int W = nums[0].size();
      int size_nums = nums.size();
      int size_q = queries.size();

      // vector<string> nums_trimmed(size_nums);
      vector<pair<string,int>> nums_indexed(size_nums);
      vector<int> out(size_q);

      for (int q = 0; q<size_q; q++)
      {
        // cout << " ==== query \n";
        // trim nums
        int stsize = queries[q][1];
        for (int i = 0; i<size_nums; i++)
        {
          // string st(stsize,'0');
          // copy(nums[i].begin()+W-stsize, nums[i].end(), st.begin());
          // nums_indexed[i].first= st;
          nums_indexed[i].first= nums[i];
          nums_indexed[i].second= i;
        }

        // print nums_trimmed
        // cout << " trimmied: \n";
        // for (int i = 0; i<size_nums; i++) cout << nums_trimmed[i] << " ";
        // cout << endl;

        // Radix sort
        for(int j = W-1; j>=W-stsize; j--)
        {
          vector<int> counter(11,0);
          vector<int> startInd(11,0);
          vector<pair<string,int>> temp=nums_indexed;

          // cout << " j: " << j << " "<< size_nums << " "<< stsize << endl;

          for (int i = 0; i<size_nums; i++)
            counter[ nums_indexed[i].first[j]-'0']++;

          // cout << " counter: \n";
          // for (int i = 0; i<counter.size(); i++) cout << counter[i] << " ";
          // cout << endl;

          for (int i = 1; i<counter.size(); i++ )  // update startInd
            startInd[i] = counter[i-1] + startInd[i-1];


          // cout << " startInd: \n";
          // for (int i = 0; i<startInd.size(); i++) cout << startInd[i] << " ";
          // cout << endl;

          for (int i = 0; i<size_nums; i++) // update location
          {
            int ind = startInd[nums_indexed[i].first[j] -'0' ]++;
            temp[ind].first = nums_indexed[i].first;
            temp[ind].second = nums_indexed[i].second;
          }

          nums_indexed =temp;

          // cout << " sorted: \n";
          // for (int i = 0; i<size_nums; i++) cout << nums_indexed[i].first<< " " << nums_indexed[i].second << "- ";
          // cout << endl;
          // cout << endl;
        }

        out[q] = nums_indexed[queries[q][0]-1].second;

      }

      return out;
    }
};

*/

class Solution
{
 public:
  vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries)
  {
    int W = nums[0].size();
    int size_nums = nums.size();
    int size_q = queries.size();

    vector<pair<string, int>> nums_indexed(size_nums);
    vector<int> out(size_q);

    // store the indices with numbers
    for (int i = 0; i < size_nums; i++)
    {
      nums_indexed[i].first = nums[i];
      nums_indexed[i].second = i;
    }

    // find the max length of the query
    int stsize = 0;
    for (int q = 0; q < size_q; q++)
      if (queries[q][1] > stsize) stsize = queries[q][1];

    vector<pair<string, int>> temp(size_nums);

    // Radix sort
    for (int j = W - 1; j >= W - stsize; j--)
    {
      vector<int> counter(11, 0);
      vector<int> startInd(11, 0);

      for (int i = 0; i < size_nums; i++) counter[nums_indexed[i].first[j] - '0']++;

      for (int i = 1; i < counter.size(); i++)  // update startInd
        startInd[i] = counter[i - 1] + startInd[i - 1];

      for (int i = 0; i < size_nums; i++)  // update location
      {
        int ind = startInd[nums_indexed[i].first[j] - '0']++;
        temp[ind].first = nums_indexed[i].first;
        temp[ind].second = nums_indexed[i].second;
      }

      nums_indexed = temp;

      // cout << " sorted: \n";
      // for (int i = 0; i<size_nums; i++) cout << "("<< nums_indexed[i].first<< ", " << nums_indexed[i].second << ") ";
      // cout << endl;

      for (int q = 0; q < size_q; q++)
      {
        if (queries[q][1] == W - j) out[q] = nums_indexed[queries[q][0] - 1].second;
        // cout << q << " " << queries[q][0] << " " << W - j << endl;
        // cout << " out: \n";
        // for (int q = 0; q<size_q; q++) cout << out[q] << " ";
        // cout << endl;
      }
      // cout << endl;
    }

    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<string> nums{"102","473","251","814"};
  // vector<vector<int>> queries{{1,1},{2,3},{4,2},{1,2}};

  // vector<string> nums{"24","37","96","04"};
  // vector<vector<int>> queries{{2,1},{2,2}};

  vector<string> nums{"857965521166535546685560513375312109196550161101146771133661158",
                      "881033111585170534680522884766545161275066790013898380563892757",
                      "187656909514180298420985948220686568469187257846585305060969613",
                      "261584091479474191164405648559002682433344242863011609630655580",
                      "221815925644813954188963609490828604514417677253200794271315314",
                      "927594748815470762376486980067059478991058166097566665835310451",
                      "788909257382875130655679621156332788036503414320372160007149734",
                      "066478715233461886488957350264263904206278380618396223024662270",
                      "525430002564539492191215844178716263923022273423041971316819550",
                      "108032616872103181557744605357875143659615647317697795122134594",
                      "200085998394753773280992871198349325567527236727391496896661601",
                      "576672024567546671655204888263592560862345212787734870386806906",
                      "949244455860549647917729420939458066769948292618896642368319105",
                      "493337357574751242813105919065697026306723435023874477221450890",
                      "118585428093535803642364690447224223285276886268719796113722499",
                      "987129076007416171899240112651086390328294849407885267166501402",
                      "738039004660185506083806189570277103067057657736900923653762399",
                      "083472221365041710021498659971195669427865801178970588778765749",
                      "852455927719476165805889915703289930908427151092769569684429822",
                      "634236165171224727114886290135186367489229874483902383062538356",
                      "792559235257345324898005534300987495352036572843628613523240681",
                      "169290822160529747973712545876252932430140939494658147749217949",
                      "892304443705089425357069456127097905441047927898154295274559033",
                      "101125664771756615058734182518453423069022267326273747565543585",
                      "878621963857102208798055231951494112444757389954786529433817634",
                      "561018133288528629225755167491418858485632902503010562473169743",
                      "417273609864313961372833720666303978990590493721422425703908751",
                      "198344613515620586788466365304588873908409225844685913941221574",
                      "084631341287054213949410516503040005984941737970753630190179712",
                      "716832338971544578887174433724624219859583858977449218631843267",
                      "659805081326335787015009638704364487122323014380260254748168749",
                      "552013688506018534109259123657550012671983771125310015495271454",
                      "037392745671385234006342690116042412497822239237277702328087340",
                      "666817472539640904764431908422873875591737675745515180964033184",
                      "519815512431328216285322188898197657738172508423373622135577773",
                      "563979521236108996178614012514078181910759685064104798787235327",
                      "004849201913024703092998366646378065273572905819099713853359421",
                      "879524707635207232023080357406677169622764254429387540697560928",
                      "527945095218226916131874961531724575448573850229591377168282654",
                      "772130183881980692862647732976497210565272172211715099431635862",
                      "974234466531729458785625279797904578336913551633034731483274442",
                      "367955115698508033438479983472664739520195075465330262444178869",
                      "641291613761773946920368560456161268880218662975772597072869205",
                      "682610192941480614588798281753454439259467630447469573021348778",
                      "432361642088881795407255265558045101025344006934978198265211263",
                      "713657691539991718274812253388867681192240111856384832484234202",
                      "669832533840102049261954783380566825244607261847261287350291254",
                      "508512429667035194837991711683299943953923754018802449933102045",
                      "820755557758127853556867644375979156918786483298407289796753785",
                      "286191815854977419231784097503731997162878284465953747811406557",
                      "619782569046247452937875418980584610916897977828783173320260949",
                      "432056980516799422587086533851112384872354894222515776471798927",
                      "640608521124074037468108636915767945103061481552401665378802475",
                      "132243592873680356135293719928400151968160526943557542259065828",
                      "522956225120777663193697797454785023332125758674735275027316164",
                      "024365163557878759244340565606695450525978899167541793870112991",
                      "591726292910274769005173481019606256349232142387498545753979618",
                      "531411119812727400079258667025907391562707051244233848430238534",
                      "144685918566536477168763216132094196246626838171450033262169442",
                      "397428608459894402230319083425164853936719033972304244571594283",
                      "396869271910975398185322542793406845523334470434395855917468390",
                      "186452774549057026632238176485868490860456485846985980124211697",
                      "426214807350505646101456465942972119548807761894098529247467286",
                      "756736021041644426085874547036409348336289988711540607036791396",
                      "820915929275495572076812886891271982973381712571473381918399374",
                      "653634113167435118876762565352651381929774131570463708203527865",
                      "829116876823911710468924530122432836393074675732277993932113930",
                      "144005434312901819747451104039006858380070410436307203768898997",
                      "384093980890172154735572748867374829226639539442222783746301808",
                      "781172569351709585497476027276144657021882883039997357095959948",
                      "739569701205858868976445065496890392531427087259723737800095708",
                      "920374323411759240415491253389408827813005894260096175183815448",
                      "482319932930973341174930628297425052496007424601804191561131203",
                      "523194357931911441371565276288745332148174610537267879021031763"};
  vector<vector<int>> queries{
      {52, 29}, {10, 44}, {65, 54}, {4, 25},  {17, 7},  {66, 41}, {67, 15}, {23, 44}, {58, 11}, {59, 29}, {72, 41},
      {30, 3},  {25, 15}, {3, 13},  {20, 47}, {27, 44}, {52, 20}, {70, 16}, {51, 22}, {50, 1},  {16, 58}, {56, 53},
      {45, 3},  {62, 34}, {70, 17}, {28, 7},  {58, 48}, {6, 48},  {19, 1},  {55, 62}, {8, 26},  {26, 19}, {68, 38},
      {34, 25}, {65, 10}, {38, 38}, {28, 42}, {51, 5},  {5, 45},  {7, 39},  {70, 49}, {26, 48}, {46, 33}, {66, 16},
      {11, 26}, {11, 43}, {1, 16},  {20, 3},  {50, 41}, {60, 18}, {25, 8},  {73, 36}, {7, 48},  {10, 17}, {54, 9},
      {11, 40}, {32, 4},  {41, 19}, {67, 51}, {48, 58}, {64, 32}, {32, 16}, {59, 27}, {30, 7},  {73, 20}};

  Solution t;

  vector<int> out = t.smallestTrimmedNumbers(nums, queries);

  cout << " answer: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  std::cout << " done \n";
  return 0;
}
