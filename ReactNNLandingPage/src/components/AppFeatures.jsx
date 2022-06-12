import React, { Component } from 'react'
import NavigationFeatures from './featuresComponents/navigationFeatures';
import JsonData from './featuresComponents/data/data2.json';

export class AppFeatures extends Component {
    // state = {
    //   landingPageData2: {},
    // }
    // getlandingPageData2() {
    //   this.setState({landingPageData2 : JsonData})
    // }
  
    // componentDidMount() {
    //   this.getlandingPageData2();
    // }
  
    render() {
      return (
        <div>
          {/* <NavigationFeatures /> */}
          {/* <Header data={this.state.landingPageData.Header} />
          <Features data={this.state.landingPageData.Features} />
          <About data={this.state.landingPageData.About} />
          <Services data={this.state.landingPageData.Services} />
          <Gallery />
          <Testimonials data={this.state.landingPageData.Testimonials} />
          <Team data={this.state.landingPageData.Team} />
          <Contact data={this.state.landingPageData.Contact} /> */}
        </div>
      )
    }
  }
  
  export default AppFeatures;