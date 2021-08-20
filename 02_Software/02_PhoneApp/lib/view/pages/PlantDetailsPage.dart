import 'dart:ui';

import 'package:build/models/Plant.dart';
import 'package:build/view/components/LineChartSample.dart';
import 'package:fl_chart/fl_chart.dart';
import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';

class PlantDetailsPage extends StatefulWidget {
  final Plant plant;

  const PlantDetailsPage({Key? key, required this.plant}) : super(key: key);

  @override
  _PlantDetailsPageState createState() => _PlantDetailsPageState();
}

class _PlantDetailsPageState extends State<PlantDetailsPage>
    with SingleTickerProviderStateMixin {
  late TabController _tabController;

  @override
  void initState() {
    _tabController = TabController(length: 4, vsync: this);
    super.initState();
  }

  @override
  void dispose() {
    super.dispose();
    _tabController.dispose();
  }

  LineChart getLineChart() {
    return new LineChart(
      LineChartData(
          // read about it in the LineChartData section
          ),
      swapAnimationDuration: Duration(milliseconds: 150), // Optional
      swapAnimationCurve: Curves.linear, // Optional
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Theme.of(context).backgroundColor,
      body: SafeArea(
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Container(
              height: 345,
              decoration: BoxDecoration(
                image: DecorationImage(
                  fit: BoxFit.cover,
                  image: widget.plant.image,
                ),
                borderRadius: BorderRadius.only(
                  bottomLeft: Radius.circular(32),
                  bottomRight: Radius.circular(32),
                ),
              ),
            ),
            SizedBox(
              height: 8,
            ),

            Expanded(
              child: Padding(
                padding: const EdgeInsets.all(8.0),
                child: LineChartSample(),
              ),
            )
            // Container(
            //   child: TabBarView(
            //     controller: _tabController,
            //     children: [
            //       Icon(Icons.directions_car),
            //       Icon(Icons.directions_transit),
            //       Icon(Icons.directions_bike),
            //       Icon(Icons.directions_bike),
            //     ],
            //   ),
            // )
            // Row(
            //   mainAxisAlignment: MainAxisAlignment.spaceAround,
            //   children: [
            //     Icon(FontAwesomeIcons.thermometer),
            //     Icon(FontAwesomeIcons.sun),
            //     Icon(FontAwesomeIcons.water),
            //     Icon(FontAwesomeIcons.tint)
            //   ],
            // )
            //   Row(
            //     mainAxisAlignment: MainAxisAlignment.spaceAround,
            //     children: [
            //       Expanded(
            //         child: SafezoneIndicator(
            //           label: "Current Temperature",
            //           currentValue: "19°C",
            //           minValue: "8°C",
            //           minIconData: FontAwesomeIcons.snowflake,
            //           maxIconData: FontAwesomeIcons.fire,
            //           maxValue: "30°C",
            //           colorGradient: LinearGradient(
            //             colors: [
            //               Color(0xff60a6ff),
            //               Color(0xff21c156),
            //               Color(0xff21c156),
            //               Color(0xffff9a4d),
            //             ],
            //             stops: [0.12, 0.22, 0.75, 0.85],
            //           ),
            //         ),
            //       ),
            //       Expanded(
            //         child: SafezoneIndicator(
            //           label: "Current Humidity",
            //           currentValue: "55%",
            //           minValue: "10%",
            //           minIconData: FontAwesomeIcons.wind,
            //           maxIconData: FontAwesomeIcons.water,
            //           maxValue: "80%",
            //           colorGradient: LinearGradient(
            //             colors: [
            //               Color(0xffffd34d),
            //               Color(0xff27c7ff),
            //               Color(0xff27c7ff),
            //               Color(0xff0016ff),
            //             ],
            //             stops: [0.2, 0.25, 0.75, 0.8],
            //           ),
            //         ),
            //       ),
            //     ],
            //   ),
            //   Container(
            //     child: SafezoneIndicator(
            //       label: "Soil moisture",
            //       currentValue: "20%",
            //       minValue: "7%",
            //       minIconData: FontAwesomeIcons.tintSlash,
            //       maxIconData: FontAwesomeIcons.tint,
            //       maxValue: "60%",
            //       colorGradient: LinearGradient(
            //         colors: [
            //           Colors.orange,
            //           Colors.green,
            //           Colors.green,
            //           Colors.orange,
            //         ],
            //         stops: [0.18, 0.23, 0.75, 0.8],
            //       ),
            //     ),
            //   ),
            //   Container(
            //     child: SafezoneIndicator(
            //       label: "Light",
            //       currentValue: "Bright",
            //       minValue: "Partial Shade",
            //       minIconData: FontAwesomeIcons.cloudSun,
            //       maxIconData: FontAwesomeIcons.sun,
            //       maxValue: "Direct light",
            //       colorGradient: LinearGradient(
            //         colors: [
            //           Colors.grey,
            //           Colors.yellow,
            //         ],
            //       ),
            //     ),
            //   ),
          ],
        ),
      ),
    );
  }
}

class SafezoneIndicator extends StatelessWidget {
  final String label;
  final String currentValue;
  final String minValue;
  final IconData minIconData;
  final IconData maxIconData;
  final String maxValue;
  final LinearGradient colorGradient;

  const SafezoneIndicator({
    Key? key,
    required this.label,
    required this.currentValue,
    required this.minValue,
    required this.minIconData,
    required this.maxIconData,
    required this.maxValue,
    required this.colorGradient,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(8.0),
      child: Container(
        decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(16),
          color: Colors.white,
          boxShadow: [
            BoxShadow(
              spreadRadius: 0,
              blurRadius: 8,
              color: Color.fromARGB(15, 0, 0, 0),
              offset: Offset(4, 4),
            ),
            BoxShadow(
              spreadRadius: 0,
              blurRadius: 8,
              color: Color.fromARGB(15, 0, 0, 0),
              offset: Offset(-4, -4),
            )
          ],
        ),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            Padding(
              padding: const EdgeInsets.all(16.0),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.center,
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Padding(
                    padding: const EdgeInsets.only(top: 4.0),
                    child: Icon(
                      this.minIconData,
                      size: 16,
                    ),
                  ),
                  Expanded(
                    child: Column(
                      children: [
                        Stack(
                          clipBehavior: Clip.none,
                          children: [
                            Padding(
                              padding: const EdgeInsets.only(
                                  left: 3.0, right: 3.0, bottom: 4.0, top: 9.0),
                              child: Container(
                                height: 10,
                                width: double.infinity,
                                decoration: BoxDecoration(
                                  color: Colors.white,
                                  gradient: this.colorGradient,
                                  boxShadow: [
                                    BoxShadow(
                                      spreadRadius: 0,
                                      blurRadius: 8,
                                      color: Color(0x20000000),
                                      offset: Offset(4, 4),
                                    ),
                                    BoxShadow(
                                      spreadRadius: 0,
                                      blurRadius: 8,
                                      color: Color(0x20000000),
                                      offset: Offset(-4, -4),
                                    )
                                  ],
                                  borderRadius: BorderRadius.circular(16.0),
                                ),
                              ),
                            ),
                            Container(
                              alignment: Alignment(0, 0),
                              child: Container(
                                child: Icon(
                                  FontAwesomeIcons.leaf,
                                  size: 24,
                                  color: Color(0xFF2B3674),
                                ),
                              ),
                            ),
                            // Container(
                            //   alignment: Alignment(-0.65, 0),
                            //   child: Padding(
                            //     padding: const EdgeInsets.only(top: 27.0),
                            //     child: Text(
                            //       this.minValue,
                            //       style: TextStyle(fontWeight: FontWeight.bold),
                            //     ),
                            //   ),
                            // ),
                            // Container(
                            //   alignment: Alignment(0.65, 0),
                            //   child: Padding(
                            //     padding: const EdgeInsets.only(top: 27.0),
                            //     child: Text(
                            //       this.maxValue,
                            //       style: TextStyle(fontWeight: FontWeight.bold),
                            //     ),
                            //   ),
                            // ),
                          ],
                        ),
                      ],
                    ),
                  ),
                  Padding(
                    padding: const EdgeInsets.only(top: 4.0),
                    child: Icon(
                      this.maxIconData,
                      size: 16,
                    ),
                  ),
                ],
              ),
            ),
            Column(
              crossAxisAlignment: CrossAxisAlignment.center,
              children: [
                Text(
                  this.currentValue,
                  style: TextStyle(
                    fontSize: 24,
                    fontWeight: FontWeight.bold,
                  ),
                ),
                Text(
                  this.label,
                  textAlign: TextAlign.left,
                  style: TextStyle(
                    color: Color(0xFFA3AED0),
                    fontSize: 12,
                    fontWeight: FontWeight.bold,
                  ),
                ),
                SizedBox(
                  height: 16.0,
                )
              ],
            ),
          ],
        ),
      ),
    );
  }
}
