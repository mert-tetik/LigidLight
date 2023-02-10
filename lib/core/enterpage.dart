import 'package:flutter/material.dart';
import 'package:flutter/src/widgets/container.dart';
import 'package:flutter/src/widgets/framework.dart';

class enterPage extends StatefulWidget {
  const enterPage({super.key});

  @override
  State<enterPage> createState() => enterPageState();
}

class enterPageState extends State<enterPage> {
  @override
  Widget build(BuildContext context) {
    return new Container(
      decoration: new BoxDecoration(color: Colors.red),
      child: new Center(
        child: Column(children: []),
      ),
    );
  }
}