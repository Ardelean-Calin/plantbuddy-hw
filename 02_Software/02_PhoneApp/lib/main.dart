import 'package:build/models/Plant.dart';
import 'package:build/view/components/PlantCardSmall.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        // This is the theme of your application.
        //
        // Try running your application with "flutter run". You'll see the
        // application has a blue toolbar. Then, without quitting the app, try
        // changing the primarySwatch below to Colors.green and then invoke
        // "hot reload" (press "r" in the console where you ran "flutter run",
        // or simply save your changes to "hot reload" in a Flutter IDE).
        // Notice that the counter didn't reset back to zero; the application
        // is not restarted.
        primarySwatch: Colors.indigo,
        backgroundColor: Color(0xFFF4F7FE),
        textTheme: Theme.of(context).textTheme.apply(
              bodyColor: Color(0xFF2B3674),
              displayColor: Color(0xFF2B3674),
            ),
        // backgroundColor: Colors.white,
        fontFamily: 'DMSans',
      ),
      home: MyHomePage(title: 'PlantBuddy'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  MyHomePage({Key? key, required this.title}) : super(key: key);

  // This widget is the home page of your application. It is stateful, meaning
  // that it has a State object (defined below) that contains fields that affect
  // how it looks.

  // This class is the configuration for the state. It holds the values (in this
  // case the title) provided by the parent (in this case the App widget) and
  // used by the build method of the State. Fields in a Widget subclass are
  // always marked "final".

  final String title;

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  final List plantList = [
    Plant(
      name: "Kalanchoe Blossfeldiana",
      location: "Living Room",
      conditions: null,
      image: AssetImage("assets/img/kalanchoe.jpg"),
    ),
    Plant(
      name: "Cyclamen Persicum",
      location: "Balcony",
      conditions: null,
      image: AssetImage("assets/img/cyclamen_persicum.jpg"),
    ),
    Plant(
      name: "Fittonia Albivenis",
      location: "Balcony",
      conditions: null,
      image: AssetImage("assets/img/fittonia_albivenis.jpg"),
    ),
  ];

  @override
  Widget build(BuildContext context) {
    // This method is rerun every time setState is called, for instance as done
    // by the _incrementCounter method above.
    //
    // The Flutter framework has been optimized to make rerunning build methods
    // fast, so that you can just rebuild anything that needs updating rather
    // than having to individually change instances of widgets.
    return Scaffold(
      backgroundColor: Theme.of(context).backgroundColor,
      body: SafeArea(
        child: Scrollbar(
          interactive: true,
          child: CustomScrollView(
            slivers: [
              SliverToBoxAdapter(
                child: SizedBox(
                  height: 16,
                ),
              ),
              SliverAppBar(
                pinned: false,
                snap: false,
                floating: false,
                backgroundColor: Theme.of(context).backgroundColor,
                title: Text(
                  "Your Plants",
                  textAlign: TextAlign.start,
                  style: TextStyle(
                    fontSize: 42,
                    fontWeight: FontWeight.bold,
                    letterSpacing: -2,
                    color: Color(0xFF2B3674),
                  ),
                ),
              ),
              SliverList(
                delegate: SliverChildBuilderDelegate(
                  (BuildContext context, int index) {
                    return Padding(
                      padding: const EdgeInsets.symmetric(
                          horizontal: 32.0, vertical: 16.0),
                      child: PlantCardSmall(plantObj: this.plantList[index]),
                    );
                  },
                  childCount: 3,
                ),
              ),
              SliverToBoxAdapter(
                child: SizedBox(
                  height: 32,
                ),
              )
            ],
          ),
        ),
      ),
      bottomNavigationBar: BottomNavigationBar(
        items: [
          BottomNavigationBarItem(icon: Icon(Icons.home), label: "Home"),
          BottomNavigationBarItem(
              icon: Icon(Icons.settings), label: "Settings"),
        ],
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () => HapticFeedback
            .heavyImpact(), // There seems to be a bug; Heavy feedback is light feedback actually
        tooltip: 'Increment',
        child: Icon(Icons.add),
      ), // This trailing comma makes auto-formatting nicer for build methods.
      floatingActionButtonLocation: FloatingActionButtonLocation.centerDocked,
    );
  }
}
