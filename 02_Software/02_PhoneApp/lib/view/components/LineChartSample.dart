import 'package:fl_chart/fl_chart.dart';
import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';

class _LineChart extends StatelessWidget {
  _LineChart({required this.dataToShow});

  final int dataToShow;

  late List<LineChartData> sampleData;

  @override
  Widget build(BuildContext context) {
    sampleData = [sampleTempData, sampleHumData];
    return LineChart(
      sampleData[dataToShow],
      swapAnimationDuration: const Duration(milliseconds: 250),
    );
  }

  LineChartData get sampleTempData => LineChartData(
        lineTouchData: lineTouchData1,
        gridData: gridData,
        titlesData: titlesData1,
        borderData: borderData,
        lineBarsData: lineBarsData1,
        minX: 0,
        maxX: 14,
        maxY: 40,
        minY: 0,
      );

  LineChartData get sampleHumData => LineChartData(
        lineTouchData: lineTouchData2,
        gridData: gridData,
        titlesData: titlesData2,
        borderData: borderData,
        lineBarsData: lineBarsData2,
        minX: 0,
        maxX: 14,
        maxY: 100,
        minY: 0,
      );

  LineTouchData get lineTouchData1 => LineTouchData(
        touchCallback: (LineTouchResponse touchResponse) {},
        handleBuiltInTouches: true,
        touchTooltipData: LineTouchTooltipData(
          tooltipBgColor: Colors.blueGrey.withOpacity(0.8),
        ),
      );

  FlTitlesData get titlesData1 => FlTitlesData(
        bottomTitles: bottomTitles,
        leftTitles: leftTitles(
          getTitles: (value) {
            switch (value.toInt()) {
              case 0:
                return '0°C';
              case 10:
                return '10°C';
              case 20:
                return '20°C';
              case 30:
                return '30°C';
              case 40:
                return '40°C';
            }
            return '';
          },
        ),
      );

  List<LineChartBarData> get lineBarsData1 => [
        lineChartBarData1_1,
        lineChartBarData1_2,
        lineChartBarData1_3,
      ];

  LineTouchData get lineTouchData2 => LineTouchData(
        enabled: false,
      );

  FlTitlesData get titlesData2 => FlTitlesData(
        bottomTitles: bottomTitles,
        leftTitles: leftTitles(
          getTitles: (value) {
            switch (value.toInt()) {
              case 10:
                return '10%';
              case 20:
                return '20%';
              case 30:
                return '30%';
              case 40:
                return '40%';
              case 50:
                return '50%';
              case 60:
                return '60%';
              case 70:
                return '70%';
              case 80:
                return '80%';
              case 90:
                return '90%';
              case 100:
                return '100%';
            }
            return '';
          },
        ),
      );

  List<LineChartBarData> get lineBarsData2 => [
        lineChartBarData2_3,
      ];

  SideTitles leftTitles({required GetTitleFunction getTitles}) => SideTitles(
        getTitles: getTitles,
        showTitles: true,
        margin: 8,
        reservedSize: 30,
        getTextStyles: (context, value) => const TextStyle(
          color: Color(0xff75729e),
          fontWeight: FontWeight.bold,
          fontSize: 14,
        ),
      );

  SideTitles get bottomTitles => SideTitles(
        showTitles: true,
        reservedSize: 22,
        margin: 10,
        getTextStyles: (context, value) => const TextStyle(
          color: Color(0xff72719b),
          fontWeight: FontWeight.bold,
          fontSize: 16,
        ),
        getTitles: (value) {
          switch (value.toInt()) {
            case 2:
              return 'Mon';
            case 7:
              return 'Tue';
            case 12:
              return 'Wed';
          }
          return '';
        },
      );

  FlGridData get gridData => FlGridData(show: false);

  FlBorderData get borderData => FlBorderData(
        show: true,
        border: const Border(
          bottom: BorderSide(color: Color(0xff4e4965), width: 4),
          left: BorderSide(color: Colors.transparent),
          right: BorderSide(color: Colors.transparent),
          top: BorderSide(color: Colors.transparent),
        ),
      );

  LineChartBarData get lineChartBarData1_1 => LineChartBarData(
        isCurved: true,
        colors: [const Color(0xff4af699)],
        barWidth: 4,
        isStrokeCapRound: true,
        dotData: FlDotData(show: false),
        belowBarData: BarAreaData(show: false),
        spots: [
          FlSpot(1, 10),
          FlSpot(3, 15),
          FlSpot(5, 14),
          FlSpot(7, 29),
          FlSpot(10, 20),
          FlSpot(12, 22),
          FlSpot(13, 34),
        ],
      );

  LineChartBarData get lineChartBarData1_2 => LineChartBarData(
        isCurved: true,
        colors: [const Color(0xd0ff0000)],
        barWidth: 2,
        isStrokeCapRound: true,
        dotData: FlDotData(show: false),
        belowBarData: BarAreaData(show: false, colors: [
          const Color(0x00aa4cfc),
        ]),
        spots: [
          FlSpot(1, 30),
          FlSpot(3, 30),
          FlSpot(7, 30),
          FlSpot(10, 30),
          FlSpot(12, 30),
          FlSpot(13, 30),
        ],
      );
  LineChartBarData get lineChartBarData1_3 => LineChartBarData(
        isCurved: true,
        colors: [const Color(0xd00000ff)],
        barWidth: 2,
        isStrokeCapRound: true,
        dotData: FlDotData(show: false),
        belowBarData: BarAreaData(show: false, colors: [
          const Color(0x00aa4cfc),
        ]),
        spots: [
          FlSpot(1, 8),
          FlSpot(3, 8),
          FlSpot(7, 8),
          FlSpot(10, 8),
          FlSpot(12, 8),
          FlSpot(13, 8),
        ],
      );

  LineChartBarData get lineChartBarData2_3 => LineChartBarData(
        isCurved: true,
        // curveSmoothness: 0,
        colors: const [Color(0xFF27b6fc)],
        barWidth: 4,
        isStrokeCapRound: true,
        dotData: FlDotData(show: false),
        belowBarData: BarAreaData(show: false),
        spots: [
          FlSpot(1, 38),
          FlSpot(3, 19),
          FlSpot(6, 75),
          FlSpot(10, 33),
          FlSpot(13, 45),
        ],
      );
}

class LineChartSample extends StatefulWidget {
  @override
  State<StatefulWidget> createState() => LineChartSampleState();
}

class LineChartSampleState extends State<LineChartSample> {
  late int dataToShow;

  @override
  void initState() {
    super.initState();
    dataToShow = 0;
  }

  @override
  Widget build(BuildContext context) {
    return AspectRatio(
      aspectRatio: 1.2,
      child: Container(
        decoration: const BoxDecoration(
          borderRadius: BorderRadius.all(Radius.circular(18)),
          gradient: LinearGradient(
            colors: [
              Color(0xff2c274c),
              Color(0xff46426c),
            ],
            begin: Alignment.bottomCenter,
            end: Alignment.topCenter,
          ),
        ),
        child: Stack(
          children: <Widget>[
            Column(
              crossAxisAlignment: CrossAxisAlignment.stretch,
              children: <Widget>[
                const SizedBox(
                  height: 70,
                ),
                Expanded(
                  child: Padding(
                    padding: const EdgeInsets.only(right: 16.0, left: 6.0),
                    child: _LineChart(
                      dataToShow: dataToShow,
                    ),
                  ),
                ),
                const SizedBox(
                  height: 10,
                ),
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                IconButton(
                  icon: Icon(
                    FontAwesomeIcons.thermometerHalf,
                    color:
                        Colors.green.withOpacity(dataToShow == 0 ? 1.0 : 0.5),
                  ),
                  onPressed: () {
                    setState(() {
                      dataToShow = 0;
                    });
                  },
                ),
                IconButton(
                  icon: Icon(
                    FontAwesomeIcons.water,
                    color:
                        Colors.orange.withOpacity(dataToShow == 1 ? 1.0 : 0.5),
                  ),
                  onPressed: () {
                    setState(() {
                      dataToShow = 1;
                    });
                  },
                ),
                IconButton(
                  icon: Icon(
                    FontAwesomeIcons.sun,
                    color:
                        Colors.green.withOpacity(dataToShow == 2 ? 1.0 : 0.5),
                  ),
                  onPressed: () {
                    setState(() {
                      dataToShow = 2;
                    });
                  },
                ),
                IconButton(
                  icon: Icon(
                    FontAwesomeIcons.tint,
                    color:
                        Colors.green.withOpacity(dataToShow == 3 ? 1.0 : 0.5),
                  ),
                  onPressed: () {
                    setState(() {
                      dataToShow = 3;
                    });
                  },
                )
              ],
            ),
          ],
        ),
      ),
    );
  }
}
