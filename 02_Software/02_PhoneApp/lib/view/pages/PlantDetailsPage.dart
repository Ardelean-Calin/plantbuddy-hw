import 'package:flutter/material.dart';

class PlantDetailsPage extends StatefulWidget {
  final AssetImage imgObj;

  const PlantDetailsPage({Key? key, required this.imgObj}) : super(key: key);

  @override
  _PlantDetailsPageState createState() => _PlantDetailsPageState();
}

class _PlantDetailsPageState extends State<PlantDetailsPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Theme.of(context).backgroundColor,
      body: SafeArea(
        child: Column(
          children: [
            Container(
              decoration: BoxDecoration(
                image: DecorationImage(
                  fit: BoxFit.cover,
                  image: widget.imgObj,
                ),
                // borderRadius: BorderRadius.only(
                //   bottomLeft: Radius.circular(32),
                //   bottomRight: Radius.circular(32),
                // ),
              ),
              height: 350,
            ),
          ],
        ),
      ),
    );
  }
}
